/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:41:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:43:25 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

t_environment	*set_sphere_sub(t_environment *env,
	t_obj *obj, char **arr, t_sphere *sp)
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
	if (check_coler(sp->color) == false || check_vec3(sp->center) == false
		|| check_double(arr[2]) == false)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}

t_environment	*set_sphere(t_environment *env, char **arr)
{
	int			i;
	t_obj		*obj;
	t_sphere	*sp;

	i = 0;
	while (arr[i])
		i ++;
	if (i != 4)
	{
		free_env(env);
		return (NULL);
	}
	obj = malloc (sizeof(t_obj));
	sp = malloc (sizeof(t_sphere));
	sp->center = ato_vec3(arr[1]);
	sp->r = ft_atod(arr[2]);
	sp->color = ato_rgb(arr[3]);
	obj->obj = sp;
	obj->next = NULL;
	obj->type = 's';
	return (set_sphere_sub(env, obj, arr, sp));
}

t_environment	*set_plane_sub(t_environment *env, t_obj *obj, t_plane *pl)
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
	if (check_norm(pl->norm) == false || check_coler(pl->color) == false
		|| check_vec3(pl->point) == false)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}

t_environment	*set_plane(t_environment *env, char **arr)
{
	int		i;
	t_obj	*obj;
	t_plane	*pl;

	i = 0;
	while (arr[i])
		i ++;
	if (i != 4)
	{
		free_env(env);
		return (NULL);
	}
	obj = malloc(sizeof(t_obj));
	pl = malloc(sizeof(t_plane));
	pl->point = ato_vec3(arr[1]);
	pl->norm = ato_vec3(arr[2]);
	pl->color = ato_rgb(arr[3]);
	obj->obj = pl;
	obj->type = 'p';
	obj->next = NULL;
	return (set_plane_sub(env, obj, pl));
}
