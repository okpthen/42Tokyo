/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:10:14 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/14 13:41:54 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

t_environment	*set_ambient(t_environment *env, char **arr)
{
	int			i;
	t_ambient	*amb;

	i = 0;
	while (arr[i])
		i ++;
	if (i != 3 || env->ambient)
	{
		free_env(env);
		return (NULL);
	}
	amb = malloc (sizeof (t_ambient));
	amb->ratio = ft_atod(arr[1]);
	amb->color = ato_rgb(arr[2]);
	env->ambient = amb;
	if (check_01(amb->ratio) == false || check_coler(amb->color) == false
		|| check_double(arr[1]) == false)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}

t_environment	*set_camera(t_environment *env, char **arr)
{
	int			i;
	t_camera	*camera;

	i = 0;
	while (arr[i])
		i ++;
	if (i != 4 || env->cam)
	{
		free_env(env);
		return (NULL);
	}
	camera = malloc(sizeof (t_camera));
	camera->pos = ato_vec3(arr[1]);
	camera->ori = ato_vec3(arr[2]);
	camera->fov = ato_fov(arr[3]);
	env->cam = camera;
	if (check_norm(camera->ori) == false || check_fov(camera->fov) == false
		|| check_vec3(camera->pos) == false)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}

t_environment	*set_light_sub(t_environment *env, t_light *light, char **arr)
{
	t_light	*tmp;

	if (!env->light)
		env->light = light;
	else
	{
		tmp = env->light;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = light;
	}
	if (check_01(light->ratio) == false || check_coler(light->color) == false
		|| check_vec3(light->pos) == false || check_double(arr[2]) == false)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}

t_environment	*set_light(t_environment *env, char **arr)
{
	int		i;
	t_light	*light;

	i = 0;
	while (arr[i])
		i ++;
	if (i != 4)
	{
		free_env(env);
		return (NULL);
	}
	light = malloc (sizeof(t_light));
	light->pos = ato_vec3(arr[1]);
	light->ratio = ft_atod(arr[2]);
	light->color = ato_rgb(arr[3]);
	light->next = NULL;
	return (set_light_sub(env, light, arr));
}
