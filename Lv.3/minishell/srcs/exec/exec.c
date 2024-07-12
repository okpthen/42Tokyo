/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:28:16 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 15:55:36 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char *cmd_name)
{
	if (ft_strcmp(cmd_name, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd_name, "exit") == 0)
		return (1);
	else
		return (0);
}

void	sighandler(int sig)
{
	usleep(200);
	if (sig == SIGQUIT)
		write(2, "Quit: 3", 7);
	write(2, "\n", 1);
	status_code('w', sig + 128, 1);
}

int	exec_init(char mode, int original_fd[2])
{
	struct sigaction		sa;
	static struct sigaction	sa_ori;

	if (mode == 's')
	{
		original_fd[0] = dup(0);
		original_fd[1] = dup(1);
		sigemptyset(&sa.sa_mask);
		sa.sa_handler = sighandler;
		sa.sa_flags = 0;
		if (sigaction(SIGINT, &sa, &sa_ori) == -1
			|| sigaction(SIGQUIT, &sa, &sa_ori) == -1)
			return (perror("sigaction"), 1);
	}
	else
	{
		if (sigaction(SIGINT, &sa_ori, NULL) == -1
			|| sigaction(SIGQUIT, &sa_ori, NULL) == -1)
			return (perror("sigaction"), 1);
	}
	return (0);
}

void	proceed_tmp(t_cmd *tmp)
{
	while (tmp != NULL)
	{
		free(tmp->heredoc);
		tmp->heredoc = NULL;
		tmp = tmp->next;
	}
}

int	exec(t_cmd *data)
{
	int		original_fd[2];
	t_cmd	*tmp;

	tmp = data;
	if (exec_init('s', original_fd) == 1)
		return (-1);
	if (get_heredoc(data) == -1)
		return (-1);
	while (data != NULL)
	{
		if ((data->argv)[0] == NULL)
		{
			status_code('w', 0, 0);
			data = data->next;
			continue ;
		}
		if (do_cmd(&data) == -1)
			return (status_code('w', 1, 0), -1);
		dup2(original_fd[0], 0);
		dup2(original_fd[1], 1);
	}
	proceed_tmp(tmp);
	return (0);
}
