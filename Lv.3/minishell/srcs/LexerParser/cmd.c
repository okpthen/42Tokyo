/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:07 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 18:49:43 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*create_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof (t_cmd));
	if (!new)
		exit(1);
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->redi = NULL;
	new->path = NULL;
	new->argv = NULL;
	new->pipe = 0;
	return (new);
}

t_ast	*skip_cmd(t_ast *ast)
{
	if (ast && ast->pipe != 0)
		ast = ast->next;
	while (ast && ast->pipe == 0)
		ast = ast->next;
	return (ast);
}

void	fix_cmd(t_cmd *cmd)
{
	int	i;

	while (cmd->next)
	{
		i = cmd->next->pipe;
		cmd->pipe = i;
		cmd = cmd->next;
	}
	if (cmd->next == NULL)
		cmd->pipe = 0;
}

t_cmd	*make_cmd(t_ast *ast)
{
	t_cmd	*cmd;
	t_cmd	*now;

	if (!ast)
		return (NULL);
	cmd = create_cmd();
	now = cmd;
	while (ast)
	{
		cmd_redi(now, ast);
		cmd_arg(now, ast);
		ast = skip_cmd(ast);
		if (ast)
		{
			now->next = create_cmd();
			now = now->next;
		}
	}
	fix_cmd(cmd);
	return (cmd);
}
