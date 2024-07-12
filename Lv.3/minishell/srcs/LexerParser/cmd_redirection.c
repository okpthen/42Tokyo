/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:02 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 18:45:39 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_redi(t_ast *ast)
{
	int	i;

	i = 0;
	if ((ast && ast ->pipe == E_NODE_PIPE) || (ast && ast ->pipe == E_NODE_SEQ))
	{
		if (ast->redi != 0)
			i ++;
		ast = ast->next;
	}
	while (ast && ast ->pipe != E_NODE_PIPE && ast->pipe != E_NODE_SEQ)
	{
		if (ast->redi != 0)
			i ++;
		ast = ast->next;
	}
	return (i);
}

void	ast_redi(t_ast *ast, int *type, char **file)
{
	int	i;

	i = 0;
	if ((ast && ast ->pipe == E_NODE_PIPE) || (ast && ast ->pipe == E_NODE_SEQ))
	{
		if (ast->redi != 0)
		{
			type[i] = ast->redi;
			file[i] = ft_strdup(ast->str);
			i ++;
		}
		ast = ast->next;
	}
	while (ast && ast ->pipe != E_NODE_PIPE && ast->pipe != E_NODE_SEQ)
	{
		if (ast->redi != 0)
		{
			type[i] = ast->redi;
			file[i] = ft_strdup(ast->str);
			i ++;
		}
		ast = ast->next;
	}
}

void	cmd_redi(t_cmd *cmd, t_ast *ast)
{
	int			count;
	char		**file;
	int			*type;
	t_redirect	*red;

	count = count_redi(ast);
	if (count == 0)
		return ;
	type = malloc (sizeof(int) * count);
	if (!type)
		exit(1);
	file = malloc (sizeof(char *) *(count + 1));
	if (!file)
		exit (1);
	file[count] = NULL;
	red = malloc (sizeof(t_redirect));
	if (!red)
		exit(1);
	ast_redi(ast, type, file);
	red->file = file;
	red->type = type;
	cmd->redi = red;
}
