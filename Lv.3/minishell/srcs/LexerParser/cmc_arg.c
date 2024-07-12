/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmc_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:19:57 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 19:49:34 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_argc(t_ast *ast)
{
	int	i;

	i = 0;
	if ((ast && ast ->pipe == E_NODE_PIPE) || (ast && ast ->pipe == E_NODE_SEQ))
	{
		if (ast->redi == 0)
			i ++;
		ast = ast ->next;
	}
	while (ast && ast ->pipe != E_NODE_PIPE && ast ->pipe != E_NODE_SEQ)
	{
		if (ast->redi == 0)
			i ++;
		ast = ast->next;
	}
	return (i);
}

void	ast_argv(t_ast *ast, char **argv)
{
	int	i;

	i = 0;
	if ((ast && ast ->pipe == E_NODE_PIPE) || (ast && ast ->pipe == E_NODE_SEQ))
	{
		if (ast->redi == 0)
		{
			argv[i] = ft_strdup(ast->str);
			if (!argv[i])
				exit(1);
			i ++;
		}
		ast = ast ->next;
	}
	while (ast && ast ->pipe != E_NODE_PIPE && ast ->pipe != E_NODE_SEQ)
	{
		if (ast->redi == 0)
		{
			argv[i] = ft_strdup(ast->str);
			if (argv[i] == NULL)
				exit (1);
			i ++;
		}
		ast = ast->next;
	}
}

void	cmd_arg(t_cmd *cmd, t_ast *ast)
{
	int		ac;
	char	**argv;

	ac = count_argc(ast);
	argv = malloc ((ac + 1) * sizeof(char *));
	if (argv == NULL)
		exit(1);
	argv[ac] = NULL;
	ast_argv(ast, argv);
	cmd->argc = ac;
	cmd->argv = argv;
	cmd->pipe = ast->pipe;
}
