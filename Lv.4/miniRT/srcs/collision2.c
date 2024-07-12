/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:04 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:05 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	is_collide_cylinder2(t_camera cam, t_cylinder *cyl,
		t_vec3 *norm, double heights[2])
{
	double	valid_t;
	t_vec3	p;
	double	height_at_collision;
	int		i;

	valid_t = -1.0;
	i = -1;
	while (++i < 2)
	{
		if (heights[i] < 0)
			continue ;
		p = vec3_sum(cam.pos, vec3_mul(cam.ori, heights[i]));
		height_at_collision = vec3_dot(vec3_sub(p, cyl->center),
				vec3_normalize(cyl->axis));
		if (height_at_collision >= 0 && height_at_collision <= cyl->height)
		{
			valid_t = heights[i];
			*norm = vec3_normalize(vec3_sub(p, vec3_sum(cyl->center,
							vec3_mul(vec3_normalize(cyl->axis),
								height_at_collision))));
			break ;
		}
	}
	return (valid_t);
}

double	sq(double a)
{
	return (a * a);
}

double	is_collide_cylinder(t_vec3 cam_pos, t_vec3 ray,
		t_cylinder *cyl, t_vec3 *norm){
	t_vec3		axis_norm;
	t_vec3		diff;
	double		abc[3];
	double		he[2];
	t_camera	cam;

	axis_norm = vec3_normalize(cyl->axis);
	diff = vec3_sub(cam_pos, cyl->center);
	abc[0] = vec3_dot(vec3_sub(ray, vec3_mul(axis_norm,
					vec3_dot(ray, axis_norm))), vec3_sub(ray,
				vec3_mul(axis_norm, vec3_dot(ray, axis_norm))));
	abc[1] = 2 * vec3_dot(vec3_sub(diff, vec3_mul(axis_norm,
					vec3_dot(diff, axis_norm))), vec3_sub(ray,
				vec3_mul(axis_norm, vec3_dot(ray, axis_norm))));
	abc[2] = vec3_dot(vec3_sub(diff, vec3_mul(axis_norm,
					vec3_dot(diff, axis_norm))), vec3_sub(diff,
				vec3_mul(axis_norm, vec3_dot(diff, axis_norm))))
		- (cyl->diameter / 2.0) * (cyl->diameter / 2.0);
	if (abc[1] * abc[1] - 4 * abc[0] * abc[2] < 0)
		return (-1.0);
	he[0] = (-abc[1] - sqrt(sq(abc[1]) - 4 * abc[0] * abc[2])) / (2 * abc[0]);
	he[1] = (-abc[1] + sqrt(sq(abc[1]) - 4 * abc[0] * abc[2])) / (2 * abc[0]);
	cam.pos = cam_pos;
	cam.ori = ray;
	return (is_collide_cylinder2(cam, cyl, norm, he));
}
