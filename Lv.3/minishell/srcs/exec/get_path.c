/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:29:10 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/21 19:29:11 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	path_with_slash(t_cmd *data)
{
	if (access((data->argv)[0], F_OK) == -1)
		return (write(2, "-bash: ", 7), write(2, (data->argv)[0],
			ft_strlen((data->argv)[0])), write(2, ": ", 2), perror(""), -1);
	if (access((data->argv)[0], X_OK) == -1)
		return (write(2, "-bash: ", 7), write(2, (data->argv)[0],
			ft_strlen((data->argv)[0])), write(2, ": ", 2), perror(""), -2);
	data->path = ft_strdup((data->argv)[0]);
	if (data->path == NULL)
		exit (1);
	return (0);
}

void	free_double_pointer(char ***p)
{
	int	i;

	i = 0;
	while ((*p)[i] != NULL)
		free((*p)[i++]);
	free((*p));
}

int	search_for_path(t_cmd *data, char **env_paths, int i)
{
	char	*semi_joined;
	char	*joined_path;

	while (env_paths[++i] != NULL)
	{
		semi_joined = ft_strjoin("/", (data->argv)[0]);
		if (semi_joined == NULL)
			exit(1);
		joined_path = ft_strjoin(env_paths[i], semi_joined);
		if ((free(semi_joined), 0) || joined_path == NULL)
			exit(1);
		if (access(joined_path, X_OK) == 0)
		{
			data->path = joined_path;
			free_double_pointer(&env_paths);
			return (0);
		}
		else
			free(joined_path);
	}
	free_double_pointer(&env_paths);
	write(2, (data->argv)[0], ft_strlen((data->argv)[0]));
	write(2, ": command not found\n", 20);
	return (-1);
}

int	path_wo_slash(t_cmd *data)
{
	char	*env_path;
	char	**env_paths;

	if (data->argv[0][0] == 0)
	{
		return (write(2, ": command not found\n", 20), -1);
	}
	env_path = ft_getenv("PATH", NULL);
	if (env_path == NULL)
	{
		return (path_with_slash(data));
	}
	env_paths = ft_split(env_path, ':');
	if (env_paths == NULL)
		return (perror("split"), -1);
	return (search_for_path(data, env_paths, -1));
}

int	get_path(t_cmd *data)
{
	data->path = NULL;
	if (ft_strchr((data->argv)[0], '/'))
		return (path_with_slash(data));
	else
		return (path_wo_slash(data));
}
