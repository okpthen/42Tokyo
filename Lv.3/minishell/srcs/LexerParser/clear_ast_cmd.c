/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ast_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:19:51 by kazokada          #+#    #+#             */
/*   Updated: 2024/06/26 16:34:07 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clear_ast(t_ast *ast)
{
	t_ast	*del;

	while (ast)
	{
		del = ast;
		ast = ast->next;
		free(del->str);
		free(del);
	}
}

void	clear_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->argc)
	{
		free(cmd->argv[i]);
		i ++;
	}
	free(cmd->argv);
	if (cmd->redi)
	{
		i = 0;
		while (cmd->redi->file[i])
		{
			free(cmd->redi->file[i]);
			i ++;
		}
		free(cmd->redi->file);
		free(cmd->redi->type);
		free(cmd->redi);
	}
	if (cmd->path)
		free(cmd->path);
}

void	clear_cmd_lst(t_cmd *cmd)
{
	t_cmd	*del;

	while (cmd)
	{
		del = cmd;
		cmd = cmd->next;
		clear_cmd(del);
		free(del);
	}
}
