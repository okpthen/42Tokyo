/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:37 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:28:16 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_ast	*creat_ast_node(char *str, int r, int t)
{
	t_ast	*new;

	new = malloc (sizeof(t_ast));
	if (!new)
		exit(1);
	new->pipe = t;
	new->redi = r;
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}

void	init_type(t_ast_type *type)
{
	type->error = 0;
	type->input = 0;
	type->output = 0;
	type->flag = 0;
	type->pre = 0;
}

int	check_pipe(char *str)
{
	int	flag;

	flag = 0;
	while (*str == '|' || *str == ';' || *str == ' '
		|| *str == '>' || *str == '<' || *str == '\t')
	{
		if (*str == '|' && flag == 0)
			flag = E_NODE_PIPE;
		else if (*str == ';' && flag == 0)
			flag = E_NODE_SEQ;
		else if ((*str == '|' && flag != 0) || (*str == ';' && flag != 0))
			return (flag + 100);
		str ++;
	}
	return (flag);
}

int	check_redirection(char *str)
{
	t_ast_type	type;

	init_type(&type);
	while (*str == '|' || *str == ';' || *str == ' '
		|| *str == '>' || *str == '<' || *str == '\t')
	{
		type_check(*str, &type);
		str ++;
	}
	if (type.error)
		return (type.error);
	else if (type.output > 0)
		return (type.output);
	else if (type.input > 0)
		return (-(type.input));
	return (0);
}
