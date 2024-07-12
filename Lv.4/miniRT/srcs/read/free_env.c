/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:34:35 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:35:23 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../include/read.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i ++;
	}
	free(arr);
}

void	free_light(t_light *light)
{
	t_light	*del;
	t_light	*tmp;

	del = light;
	while (del)
	{
		tmp = del->next;
		free(del);
		del = tmp;
	}
}

void	free_obj(t_obj	*obj)
{
	t_obj	*del;
	t_obj	*tmp;

	del = obj;
	while (del)
	{
		tmp = del->next;
		free(del->obj);
		free(del);
		del = tmp;
	}
}

void	free_env(t_environment *env)
{
	if (env->light)
		free_light(env->light);
	if (env->obj)
		free_obj(env->obj);
	if (env->cam)
		free(env->cam);
	if (env->ambient)
		free(env->ambient);
	free(env);
}
