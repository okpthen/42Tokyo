/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:07:50 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 15:31:17 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int		do_single_com(t_cmd **data, int *end_status);
void	proceed_data(t_cmd **data);

int	close_all_children(int io_fd[2], int pipe_fd[2][2])
{
	if (pipe_fd[0][0] != io_fd[0] && pipe_fd[0][0] != io_fd[1]
		&& pipe_fd[0][0] != -1)
		close(pipe_fd[0][0]);
	if (pipe_fd[0][1] != io_fd[0] && pipe_fd[0][1] != io_fd[1]
		&& pipe_fd[0][1] != -1)
		close(pipe_fd[0][1]);
	if (pipe_fd[1][0] != io_fd[0] && pipe_fd[1][0] != io_fd[1]
		&& pipe_fd[1][0] != -1)
		close(pipe_fd[1][0]);
	if (pipe_fd[1][1] != io_fd[0] && pipe_fd[1][1] != io_fd[1]
		&& pipe_fd[1][1] != -1)
		close(pipe_fd[1][1]);
	return (0);
}

int	do_mul_com2(t_cmd **data, int *prev_fd, int pipe_fd[2][2])
{
	if ((*data)->heredoc != NULL)
	{
		write(pipe_fd[1][1], (*data)->heredoc, ft_strlen((*data)->heredoc));
		multi_close(&pipe_fd[1][0], &pipe_fd[1][1], NULL, NULL);
	}
	multi_close(prev_fd, &pipe_fd[0][1], NULL, NULL);
	*prev_fd = pipe_fd[0][0];
	(*data) = (*data)->next;
	return (0);
}

int	do_mul_com(t_cmd **data, int *prev_fd, pid_t *child)
{
	int	pipe_fd[2][2];
	int	io_fd[2];

	if (get_iofd((*data), io_fd, pipe_fd, prev_fd) == -1)
	{
		*prev_fd = pipe_fd[0][0];
		(*data) = (*data)->next;
		return (close(*prev_fd), close(pipe_fd[0][1]), -1);
	}
	*child = fork();
	if (*child == -1)
		return (multi_close(prev_fd, &pipe_fd[0][1], NULL, NULL),
			write(2, "bash: fork: ", 12), perror(""), -1);
	if (*child == 0)
	{
		close_all_children(io_fd, pipe_fd);
		do_each_cmd(data, io_fd, *prev_fd, 1);
	}
	return (do_mul_com2(data, prev_fd, pipe_fd));
}

int	do_single_com_fork(t_cmd **data, int *prev_fd, pid_t *child)
{
	int	pipe_fd[2][2];
	int	io_fd[2];

	if (get_iofd((*data), io_fd, pipe_fd, prev_fd) == -1)
	{
		status_code('w', 1, 0);
		(*data) = (*data)->next;
		return (-1);
	}
	*child = fork();
	if (*child == -1)
		return (close(*prev_fd), write(2, "bash: fork: ", 12), perror(""), -1);
	if (*child == 0)
	{
		close_all_children(io_fd, pipe_fd);
		do_each_cmd(data, io_fd, *prev_fd, 1);
	}
	if ((*data)->heredoc != NULL)
	{
		write(pipe_fd[1][1], (*data)->heredoc, ft_strlen((*data)->heredoc));
		multi_close(&pipe_fd[1][0], &pipe_fd[1][1], NULL, NULL);
	}
	(*data) = (*data)->next;
	return (close(*prev_fd), 0);
}

int	do_cmd(t_cmd **data)
{
	int		prev_fd;
	int		end_status;
	pid_t	child;

	prev_fd = 0;
	child = -1;
	if ((*data)->pipe != E_NODE_PIPE && is_builtin(((*data)->argv)[0]))
		return (do_single_com((data), &end_status));
	while ((*data) != NULL && (*data)->pipe == E_NODE_PIPE)
		if (do_mul_com((data), &prev_fd, &child) == -1)
			return (proceed_data(data), -1);
	if ((*data) != NULL)
		if (do_single_com_fork((data), &prev_fd, &child) == -1)
			return (proceed_data(data), -1);
	if (child != -1)
	{
		waitpid(child, &end_status, 0);
		status_code('w', WEXITSTATUS(end_status), 0);
	}
	while ((waitpid(-1, NULL, 0)) > 0)
		;
	return (1);
}
