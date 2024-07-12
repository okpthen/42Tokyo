/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:09 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:10 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_rgb	get_diffuse_color2(t_environment *env, t_vec3 norm,
		t_rgb ret, t_vec3 point){
	if (can_reach_the_light(point, vec3_sub(env->light->pos, point),
			env->light->pos, env) == 1)
	{
		ret.r = (int)((double)env->light->color.r * env->light->ratio
				* (double)ret.r / 255.0f * vec3_dot(vec3_normalize(norm),
					vec3_normalize(vec3_sub(env->light->pos, point))));
		ret.g = (int)((double)env->light->color.g * env->light->ratio
				* (double)ret.g / 255.0f * vec3_dot(vec3_normalize(norm),
					vec3_normalize(vec3_sub(env->light->pos, point))));
		ret.b = (int)((double)env->light->color.b * env->light->ratio
				* (double)ret.b / 255.0f * vec3_dot(vec3_normalize(norm),
					vec3_normalize(vec3_sub(env->light->pos, point))));
		return (ret);
	}
	else
		return (assign_color(0, 0, 0));
}

t_rgb	get_diffuse_color(t_vec3 ray_mul, t_environment *env,
		t_vec3 norm, t_obj *obj){
	t_rgb	ret;
	t_vec3	point;

	point = vec3_sum(ray_mul, env->cam->pos);
	if (vec3_dot(ray_mul, norm) > 0)
		norm = vec3_mul(norm, -1);
	if (vec3_dot(vec3_sub(env->light->pos, point), norm) <= 0)
		return (assign_color(0, 0, 0));
	if (obj->type == 'p')
		ret = ((t_plane *)(obj->obj))->color;
	else if (obj->type == 's')
		ret = ((t_sphere *)(obj->obj))->color;
	else if (obj->type == 'c')
		ret = ((t_cylinder *)(obj->obj))->color;
	else
		ret = assign_color(0, 0, 0);
	return (get_diffuse_color2(env, norm, ret, point));
}

t_rgb	get_full_color(t_vec3 ray_mul, t_environment *env,
		t_vec3 norm, t_obj *obj){
	t_rgb	a;
	t_rgb	b;

	a = get_ambient_color(env->ambient, obj);
	b = get_diffuse_color(ray_mul, env, norm, obj);
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return (a);
}

int	get_color4ray(t_vec3 ray, t_environment *env)
{
	double	min;
	double	t;
	int		color;
	t_obj	*now;
	t_vec3	norm;

	min = DBL_MAX;
	now = env->obj;
	while (now != NULL)
	{
		t = is_collide_obj(ray, env, now, &norm);
		if (t > 0 && t < min)
		{
			min = t;
			color = rgb2hex(get_full_color(vec3_mul(ray, t), env, norm, now));
		}
		now = now->next;
	}
	if (min == DBL_MAX)
		color = 0xFF;
	return (color);
}
