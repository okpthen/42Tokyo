/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:01 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:02 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	an_norm(t_vec3 cam_pos, t_vec3 ray_mul,
	t_sphere *sphere, t_vec3 *norm)
{
	*norm = vec3_normalize(vec3_sub(vec3_sum(cam_pos, ray_mul),
				sphere->center));
}

double	is_collide_sphere(t_vec3 cam_pos, t_vec3 ray,
	t_sphere *sphere, t_vec3 *norm)
{
	double	a;
	double	b;
	double	c;
	double	t;

	a = vec3_dot(ray, ray);
	b = 2 * (vec3_dot(cam_pos, ray) - vec3_dot(ray, sphere->center));
	c = -2 * vec3_dot(cam_pos, sphere->center) + vec3_dot(sphere->center,
			sphere->center) + vec3_dot(cam_pos, cam_pos)
		- sphere->r * sphere->r;
	if (b * b - 4 * a * c >= 0)
	{
		t = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (t <= 0)
		{
			t = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
			if (t <= 0)
				return (-1.0f);
			else
				return (an_norm(cam_pos, vec3_mul(ray, t), sphere, norm), t);
		}
		return (an_norm(cam_pos, vec3_mul(ray, t), sphere, norm), t);
	}
	return (-1.0f);
}

double	is_collide_plane(t_vec3 cam_pos, t_vec3 ray,
	t_plane *plane, t_vec3 *norm)
{
	double	t;

	t = (vec3_dot(vec3_sub(plane->point, cam_pos),
				plane->norm) / vec3_dot(ray, plane->norm));
	if (vec3_dot(ray, plane->norm) < 0)
	{
		norm->x = plane->norm.x;
		norm->y = plane->norm.y;
		norm->z = plane->norm.z;
	}
	else
	{
		norm->x = -plane->norm.x;
		norm->y = -plane->norm.y;
		norm->z = -plane->norm.z;
	}
	if (t > 0)
		return (t);
	else
		return (-1.0f);
}

double	is_collide_obj(t_vec3 ray, t_environment *env, t_obj *now, t_vec3 *norm)
{
	if (now->type == 'p')
		return (is_collide_plane(env->cam->pos,
				ray, (t_plane *)(now->obj), norm));
	else if (now->type == 's')
		return (is_collide_sphere(env->cam->pos,
				ray, (t_sphere *)(now->obj), norm));
	else if (now->type == 'c')
		return (is_collide_cylinder(env->cam->pos,
				ray, (t_cylinder *)(now->obj), norm));
	else
		return (write(2, "Hi, du****s", 11));
}

double	is_collide_obj2(t_vec3 ray, t_vec3 pos, t_obj *now, t_vec3 *norm)
{
	if (now->type == 'p')
		return (is_collide_plane(pos, ray, (t_plane *)(now->obj), norm));
	if (now->type == 's')
		return (is_collide_sphere(pos, ray, (t_sphere *)(now->obj), norm));
	if (now->type == 'c')
		return (is_collide_cylinder(pos,
				ray, (t_cylinder *)(now->obj), norm));
	else
		return (write(2, "Hi, du****s", 11));
}
