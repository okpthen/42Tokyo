/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:19:42 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:27:58 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_status(char c, int status)
{
	if (c == '\"' && status == 0)
		status += DQUOTE;
	else if (c == '\"' && (status & DQUOTE))
		status -= DQUOTE;
	else if (c == '\'' && status == 0)
		status += QUOTE;
	else if (c == '\'' && (status & QUOTE))
		status -= QUOTE;
	else if (c == '\\' && !(status & ESCAPED))
		status += ESCAPED;
	else if (status & ESCAPED)
		status -= ESCAPED;
	return (status);
}

int	input_check(char *str)
{
	int		status;

	status = 0;
	while (*str)
	{
		status = check_status(*str, status);
		str ++;
	}
	if (status == 0)
		return (0);
	else
		return (1);
}
