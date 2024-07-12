/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinkpad-wsl <thinkpad-wsl@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:33 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 18:49:46 by thinkpad-ws      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*make_cmd_lst(char	*str)
{
	int		error;
	t_ast	*ast;
	t_cmd	*cmd;

	if (input_check(str) == 1)
	{
		printf("unclosed quotes or special characters\n");
		return (NULL);
	}
	ast = split_word(str);
	error = check_error_ast(ast);
	if (error)
	{
		status_code('w', 2, 0);
		print_error(error);
		clear_ast(ast);
		return (NULL);
	}
	expand_ast_env(ast);
	cmd = make_cmd(ast);
	clear_ast(ast);
	return (cmd);
}
