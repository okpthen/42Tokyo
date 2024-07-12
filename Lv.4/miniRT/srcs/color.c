/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:07 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:07 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	integer_clip(int num, int min, int max)
{
	if (num < min)
		return (min);
	else if (num > max)
		return (max);
	else
		return (num);
}

int	rgb2hex(t_rgb color)
{
	return (integer_clip(color.r, 0, 255) * 256 * 256
		+ integer_clip(color.g, 0, 255) * 256
		+ integer_clip(color.b, 0, 255));
}

t_rgb	get_ambient_color(t_ambient *ambient, t_obj *obj)
{
	t_rgb	ret;

	if (obj->type == 'p')
		ret = ((t_plane *)(obj->obj))->color;
	else if (obj->type == 's')
		ret = ((t_sphere *)(obj->obj))->color;
	else if (obj->type == 'c')
		ret = ((t_cylinder *)(obj->obj))->color;
	ret.r = (int)((double)ambient->color.r
			* ambient->ratio * (double)ret.r / 255.0f);
	ret.g = (int)((double)ambient->color.g
			* ambient->ratio * (double)ret.g / 255.0f);
	ret.b = (int)((double)ambient->color.b
			* ambient->ratio * (double)ret.b / 255.0f);
	return (ret);
}

int	can_reach_the_light(t_vec3 pos, t_vec3 ray,
		t_vec3 light_pos, t_environment *env){
	double	t;
	double	max_t;
	t_vec3	norm;
	t_obj	*now;

	if (fabs(ray.x) >= 1e-6)
		max_t = (light_pos.x - pos.x) / ray.x;
	else if (fabs(ray.y) >= 1e-6)
		max_t = (light_pos.y - pos.y) / ray.y;
	else
		max_t = (light_pos.z - pos.z) / ray.z;
	now = env->obj;
	pos = vec3_sum(pos, vec3_mul(ray, 0.001953125f));
	while (now != NULL)
	{
		t = is_collide_obj2(ray, pos, now, &norm);
		if (t > 0 && t < max_t)
			return (0);
		now = now->next;
	}
	return (1);
}

t_rgb	assign_color(int a, int b, int c)
{
	t_rgb	r;

	r.r = a;
	r.g = b;
	r.b = c;
	return (r);
}
