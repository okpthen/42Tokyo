/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iofd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:23:58 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 20:12:29 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	get_iofd20(t_cmd *data, int io_fd[2], int *i)
{
	int	tmpfd;

	close(io_fd[0]);
	tmpfd = open(data->redi->file[*i], O_RDONLY);
	if (tmpfd == -1)
		return (write(2, "-bash: ", 7),
			write(2, data->redi->file[*i],
				ft_strlen(data->redi->file[*i])),
			write(2, ": ", 2),
			perror(""), -1);
	io_fd[0] = tmpfd;
	return (0);
}

int	get_iofd21(int io_fd[2], int pipe_fd[2][2])
{
	if (pipe(pipe_fd[1]) == -1)
		return (perror("pipe"), -1);
	close(io_fd[0]);
	io_fd[0] = pipe_fd[1][0];
	return (0);
}

int	get_iofd22(t_cmd *data, int io_fd[2], int *i)
{
	int	tmpfd;
	int	tmp;

	tmpfd = 999;
	tmpfd = open(data->redi->file[*i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (tmpfd == 0 || tmpfd == 1)
	{
		tmp = dup(tmpfd);
		close(tmpfd);
		tmpfd = tmp;
	}
	if (tmpfd == -1)
		return (perror("minishell"), -1);
	if (io_fd[1] != 1)
		close(io_fd[1]);
	io_fd[1] = tmpfd;
	return (0);
}

int	get_iofd23(t_cmd *data, int io_fd[2], int *i)
{
	int	tmpfd;
	int	tmp;

	tmpfd = open(data->redi->file[*i], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (tmpfd == -1)
		return (perror("minishell"), -1);
	if (tmpfd == 0 || tmpfd == 1)
	{
		tmp = dup(tmpfd);
		close(tmpfd);
		tmpfd = tmp;
	}
	if (io_fd[1] != 1)
		close(io_fd[1]);
	io_fd[1] = tmpfd;
	return (0);
}
