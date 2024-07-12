/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:45 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:28:17 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	delimineter_number(char *str)
{
	int		j;

	j = 0;
	while (*str == '|' || *str == ';' || *str == ' '
		|| *str == '>' || *str == '<' || *str == '\t')
	{
		str ++;
		j ++;
	}
	return (j);
}

int	check_delimineter(char *str)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (str[i])
	{
		if ((status == 0 && str[i] == ';') || (status == 0 && str[i] == '|'))
			return (i);
		if ((status == 0 && str[i] == '>') || (status == 0 && str[i] == '<'))
			return (i);
		if ((status == 0 && str[i] == ' ') || (status == 0 && str[i] == '\t'))
			return (i);
		status = check_status(str[i], status);
		i ++;
	}
	return (0);
}

void	split_word_sub(t_ast *node)
{
	t_a	a;

	a.i = check_delimineter(node->str);
	if (a.i > 0)
	{
		a.j = delimineter_number(&node->str[a.i]);
		a.r = check_redirection(&node->str[a.i]);
		a.t = check_pipe(&node->str[a.i]);
		if (node->str[a.i + a.j] == '\0')
		{
			node->str[a.i] = '\0';
			check_error_last(node, a.r, a.t);
			return ;
		}
		node->next = creat_ast_node(&node->str[a.i + a.j], a.r, a.t);
		node->str[a.i] = '\0';
		split_word_sub(node->next);
	}
}

t_ast	*creat_first_ast(char *str)
{
	t_ast	*node;
	int		i;

	if (*str == '|' || *str == ';' || *str == ' '
		|| *str == '>' || *str == '<' || *str == '\t')
	{
		node = malloc (sizeof(t_ast));
		if (!node)
			exit(1);
		i = delimineter_number(str);
		node->pipe = check_pipe(str);
		node->redi = check_redirection(str);
		node->next = NULL;
		str = str + i;
		node->str = ft_strdup(str);
		return (node);
	}
	return (creat_ast_node(str, 0, 0));
}

t_ast	*split_word(char *str)
{
	t_ast	*start;

	start = creat_first_ast(str);
	split_word_sub(start);
	return (start);
}
