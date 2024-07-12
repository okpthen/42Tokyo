/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:28:27 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 20:12:06 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	builtin_find_exec(t_cmd *data)
{
	if (ft_strcmp(data->argv[0], "echo") == 0)
		return (builtin_echo(data->argc, data->argv));
	else if (ft_strcmp(data->argv[0], "cd") == 0)
		return (builtin_cd(data->argc, data->argv));
	else if (ft_strcmp(data->argv[0], "pwd") == 0)
		return (builtin_pwd(data->argc, data->argv));
	else if (ft_strcmp(data->argv[0], "export") == 0)
		return (builtin_export(data->argc, data->argv));
	else if (ft_strcmp(data->argv[0], "unset") == 0)
		return (builtin_unset(data->argc, data->argv));
	else if (ft_strcmp(data->argv[0], "env") == 0)
		return (builtin_env(data->argc, data->argv));
	else if (ft_strcmp(data->argv[0], "exit") == 0)
		return (builtin_exit(data->argc, data->argv));
	else
		return (-1);
	return (0);
}

void	proceed_data(t_cmd **data)
{
	if ((*data) != NULL)
		*data = (*data)->next;
}
