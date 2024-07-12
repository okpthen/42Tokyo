/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:19:24 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/14 13:54:35 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../include/read.h"

t_environment	*init_env(void)
{
	t_environment	*env;

	env = malloc (sizeof(t_environment));
	if (!env)
	{
		write(2, "malloc error\n", 14);
		exit(1);
	}
	env->light = NULL;
	env->obj = NULL;
	env->ambient = NULL;
	env->cam = NULL;
	return (env);
}

t_environment	*str_env_str(t_environment *env, char *str)
{
	char	**arr;

	arr = ft_split(str, ' ');
	if (ft_strcmp("A", arr[0]) == 0)
		env = set_ambient(env, arr);
	else if (ft_strcmp("C", arr[0]) == 0)
		env = set_camera(env, arr);
	else if (ft_strcmp("L", arr[0]) == 0)
		env = set_light(env, arr);
	else if (ft_strcmp("sp", arr[0]) == 0)
		env = set_sphere(env, arr);
	else if (ft_strcmp("pl", arr[0]) == 0)
		env = set_plane(env, arr);
	else if (ft_strcmp("cy", arr[0]) == 0)
		env = set_cylinder(env, arr);
	else
	{
		free_env(env);
		return (NULL);
	}
	free_arr(arr);
	return (env);
}

bool	file_name(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	if (size <= 3)
		return (false);
	if (str[size - 1] == 't' && str[size - 2] == 'r' && str[size - 3] == '.')
		return (true);
	else
		return (false);
}

t_environment	*make_env_sub(char *file)
{
	int				fd;
	char			*str;
	t_environment	*env;

	fd = open(file, O_RDONLY);
	env = init_env();
	if (fd < 0 || env == NULL)
		return (free(env), NULL);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		if (*str == '\n')
		{
			free(str);
			continue ;
		}
		env = str_env_str(env, str);
		free(str);
		if (!env)
			return (NULL);
	}
	return (env);
}

t_environment	*make_env(char *str)
{
	t_environment	*env;

	if (file_name(str) == false)
		return (NULL);
	env = make_env_sub(str);
	if (!env)
		return (NULL);
	if (env->ambient == NULL || env->cam == NULL
		|| env->light == NULL)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}
