/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:13 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:42:34 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_error(int num)
{
	if (num == E_ERROR_PIPE)
		write(2, "-bash: syntax error near unexpected token `|'\n", 47);
	else if (num == E_ERROR_NEWLINE)
		write(2, "-bash: syntax error near unexpected token `newline'\n", 53);
	else if (num == E_ERROR_REDIRECT_APPEND)
		write(2, "-bash: syntax error near unexpected token `>>'\n", 48);
	else if (num == E_ERROR_REDIRECT_HEREDOC)
		write(2, "-bash: syntax error near unexpected token `<<'\n", 48);
	else if (num == E_ERROR_REDIRECT_IN)
		write(2, "-bash: syntax error near unexpected token `<'\n", 47);
	else if (num == E_ERROR_REDIRECT_OUT)
		write(2, "-bash: syntax error near unexpected token `>>'\n", 48);
	else if (num == E_ERROR_SEQ)
		write(2, "-bash: syntax error near unexpected token `>>'\n", 48);
	else if (num == E_ERROR_OTHER)
		write(2, "-bash: syntax error near unexpected token `?'\n", 47);
}

int	check_error_ast(t_ast *ast)
{
	if (ast->pipe == 1)
		return (E_ERROR_PIPE);
	else if (ast->pipe == 2)
		return (E_ERROR_SEQ);
	while (ast)
	{
		if (ast->pipe == 101 || ast->pipe == 102)
			return (ast->pipe - 90);
		if (!(-2 <= ast->redi && ast->redi <= 2))
			return (ast->redi);
		else if (ast->redi == -2)
			ast->redi = E_NODE_REDIRECT_IN_HEREDOC;
		else if (ast->redi == -1)
			ast->redi = E_NODE_REDIRECT_IN;
		else if (ast->redi == 1)
			ast->redi = E_NODE_REDIRECT_OUT;
		else if (ast->redi == 2)
			ast->redi = E_NODE_REDIRECT_OUT_APPEND;
		ast = ast->next;
	}
	return (0);
}

void	check_error_last(t_ast *node, int r, int t)
{
	if (t == E_NODE_PIPE)
		node->pipe = E_NODE_PIPE + 100;
	if (r == -2 || r == -1 || r == 1 || r == 2)
		node->redi = E_ERROR_NEWLINE;
	else if (r != 0)
		node->redi = r;
}
