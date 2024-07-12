/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:25:21 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:22 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include "../include/vector.h"

t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vec3	vec3_mul(t_vec3 a, double n)
{
	t_vec3	r;

	r.x = a.x * n;
	r.y = a.y * n;
	r.z = a.z * n;
	return (r);
}

t_vec3	vec3_sum(t_vec3 a, t_vec3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_vec3	vec3_normalize(t_vec3 a)
{
	double	l;
	t_vec3	ret;

	l = sqrt(vec3_dot(a, a));
	if (fabs(l) < 1e-6)
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 0;
		return (ret);
	}
	ret.x = a.x / l;
	ret.y = a.y / l;
	ret.z = a.z / l;
	return (ret);
}

double	vec3_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
