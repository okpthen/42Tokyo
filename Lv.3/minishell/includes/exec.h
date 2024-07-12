/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:36:32 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 17:39:47 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../includes/minishell.h"
# include "../includes/cmd.h"
# include "../includes/ast.h"

int		builtin_echo(int ac, char **av);
int		builtin_cd(int ac, char **av);
int		builtin_pwd(int ac, char **av);
int		builtin_export(int ac, char **av);
int		builtin_unset(int ac, char **av);
int		builtin_env(int ac, char **av);
int		builtin_exit(int ac, char **av);

int		builtin_find_exec(t_cmd *data);
void	multi_close(int *fd1, int *fd2, int *fd3, int *fd4);
int		get_path(t_cmd *data);
int		exec(t_cmd *data);
int		get_heredoc(t_cmd *data);
int		do_each_cmd(t_cmd **data, int io_fd[2], int prev_fd, int is_fork);
int		is_builtin(char *cmd_name);
int		get_iofd(t_cmd *data, int io_fd[2], int pipe_fd[2][2], int *prev_fd);
int		do_cmd(t_cmd **data);

#endif
