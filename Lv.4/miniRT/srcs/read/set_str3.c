/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:42:10 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:43:49 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

t_environment	*set_cylinder_sub(t_environment *env, t_cylinder *cy,
	t_obj *obj, char	**arr)
{
	t_obj	*tmp;

	if (!env->obj)
		env->obj = obj;
	else
	{
		tmp = env->obj;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
	if (check_coler(cy->color) == false || check_norm(cy->axis) == false
		|| check_vec3(cy->center) == false
		|| check_double(arr[3]) == false || check_double(arr[4]) == false)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}

t_environment	*set_cylinder(t_environment *env, char **arr)
{
	int			i;
	t_cylinder	*cy;
	t_obj		*obj;

	i = 0;
	while (arr[i])
		i ++;
	if (i != 6)
	{
		free_env(env);
		return (NULL);
	}
	cy = malloc(sizeof(t_cylinder));
	obj = malloc(sizeof(t_obj));
	cy->center = ato_vec3(arr[1]);
	cy->axis = ato_vec3(arr[2]);
	cy->diameter = ft_atod(arr[3]);
	cy->height = ft_atod(arr[4]);
	cy->color = ato_rgb(arr[5]);
	obj->type = 'c';
	obj->obj = cy;
	obj->next = NULL;
	return (set_cylinder_sub(env, cy, obj, arr));
}
