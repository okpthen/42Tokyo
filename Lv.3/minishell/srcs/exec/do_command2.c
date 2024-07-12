/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:08:17 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 20:08:53 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	multi_close(int *fd1, int *fd2, int *fd3, int *fd4)
{
	if (fd1 != NULL && *fd1 != -1)
		close(*fd1);
	if (fd2 != NULL && *fd2 != -1)
		close(*fd2);
	if (fd3 != NULL && *fd3 != -1)
		close(*fd3);
	if (fd4 != NULL && *fd4 != -1)
		close(*fd4);
}

int	case_builtin(t_cmd **data, int ori_fd[2], int is_fork)
{
	int	rel;

	rel = builtin_find_exec(*data);
	close(0);
	dup2(ori_fd[0], 0);
	if (is_fork)
		exit(rel);
	(*data) = (*data)->next;
	return (rel);
}

void	condition_closer(int fd, int val)
{
	if (fd != val && fd != -1)
		close(fd);
}

int	do_each_cmd(t_cmd **data, int io_fd[2], int prev_fd, int is_fork)
{
	int	rel;
	int	ori_fd[2];

	ori_fd[0] = dup(0);
	if (dup2(io_fd[0], 0) == -1)
		return (-1);
	if (dup2(io_fd[1], 1) == -1)
		return (close(io_fd[0]), -1);
	condition_closer(prev_fd, 0);
	condition_closer(io_fd[0], 0);
	condition_closer(io_fd[1], 1);
	if (is_builtin(((*data)->argv)[0]))
		return (case_builtin(data, ori_fd, is_fork));
	rel = get_path(*data);
	if (rel < 0)
	{
		clear_cmd_lst(*data);
		free_env(NULL);
		rl_clear_history();
		exit(128 + rel);
	}
	rel = execve((*data)->path, (*data)->argv, get_path_in_string(NULL));
	if (rel == -1)
		perror("execution_failed");
	exit(1);
}

int	do_single_com(t_cmd **data, int *end_status)
{
	int	pipe_fd[2][2];
	int	io_fd[2];
	int	prev_fd;

	prev_fd = 0;
	if (get_iofd((*data), io_fd, pipe_fd, &prev_fd) == -1)
	{
		(*data) = (*data)->next;
		return (-1);
	}
	*end_status = do_each_cmd((data), io_fd, prev_fd, 0);
	status_code('w', *end_status, 0);
	return (0);
}
