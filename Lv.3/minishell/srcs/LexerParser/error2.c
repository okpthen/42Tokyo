/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:18 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:28:05 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	type_check1(char c, t_ast_type *type)
{
	if (c == '>' && type->pre != '>')
		type->output = 1;
	if (c == '<' && type->pre != '<')
		type->input = 1;
	if (c == '>' && type->pre == '>')
	{
		type->output = 2;
		type->flag = 1;
	}
	if (c == '<' && type->pre == '<')
	{
		type->input = 2;
		type->flag = 1;
	}
	if (type->output == 1 && (c == '\t' || c == ' '))
		type->flag = 1;
	if (type->input == 1 && (c == '\t' || c == ' '))
		type->flag = 1;
}

void	type_check2(char c, t_ast_type *type)
{
	if (c == '>' && type->error == 0)
		type->error = E_ERROR_REDIRECT_OUT;
	if (c == '<' && type->error == 0)
		type->error = E_ERROR_REDIRECT_IN;
	if (c == '>' && type->error == E_ERROR_REDIRECT_OUT && type->pre == '>')
		type->error = E_ERROR_REDIRECT_APPEND;
	if (c == '<' && type->error == E_ERROR_REDIRECT_IN && type->pre == '<')
		type->error = E_ERROR_REDIRECT_HEREDOC;
	if (c == '|' && type->error == 0)
		type->error = E_ERROR_PIPE;
	if (c == ';' && type->error == 0)
		type->error = E_ERROR_SEQ;
}

void	type_check(char c, t_ast_type *type)
{
	if (type->flag == 0)
		type_check1(c, type);
	else if (type->flag == 1)
		type_check2(c, type);
	type->pre = c;
}
