/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iofd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:23:55 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 20:12:18 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	get_iofd20(t_cmd *data, int io_fd[2], int *i);
int	get_iofd21(int io_fd[2], int pipe_fd[2][2]);
int	get_iofd22(t_cmd *data, int io_fd[2], int *i);
int	get_iofd23(t_cmd *data, int io_fd[2], int *i);

int	get_iofd2(t_cmd *data, int io_fd[2], int pipe_fd[2][2])
{
	int	i;

	i = -1;
	while (data->redi != NULL && (data->redi->file)[++i] != NULL)
	{
		if ((data->redi->type)[i] & E_NODE_REDIRECT_IN)
		{
			if (get_iofd20(data, io_fd, &i) == -1)
				return (-1);
		}
		else if ((data->redi->type)[i] & E_NODE_REDIRECT_IN_HEREDOC)
		{
			if (get_iofd21(io_fd, pipe_fd) == -1)
				return (-1);
		}
		else if ((data->redi->type)[i] & E_NODE_REDIRECT_OUT)
		{
			if (get_iofd22(data, io_fd, &i) == -1)
				return (-1);
		}
		else if ((data->redi->type)[i] & E_NODE_REDIRECT_OUT_APPEND)
			if (get_iofd23(data, io_fd, &i) == -1)
				return (-1);
	}
	return (0);
}

int	get_iofd(t_cmd *data, int io_fd[2], int pipe_fd[2][2], int *prev_fd)
{
	io_fd[0] = *prev_fd;
	pipe_fd[0][0] = -1;
	pipe_fd[0][1] = -1;
	if (data->pipe == E_NODE_PIPE)
	{
		if (pipe(pipe_fd[0]) == -1)
			return (perror("pipe"), -1);
		io_fd[1] = pipe_fd[0][1];
	}
	else
		io_fd[1] = 1;
	pipe_fd[1][0] = -1;
	pipe_fd[1][1] = -1;
	if (data->redi == NULL)
		return (0);
	return (get_iofd2(data, io_fd, pipe_fd));
}
