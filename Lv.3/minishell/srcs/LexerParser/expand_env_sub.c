/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:23 by kazokada          #+#    #+#             */
/*   Updated: 2024/06/30 15:32:17 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*only_env(char *str)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (*str == '$')
	{
		j = 1;
		while (str[j] && check_env_delimiter(str[j], j))
			j ++;
		while (str[i])
			i ++;
		if (i == j)
		{
			if (ft_getenv(str, NULL) == NULL)
			{
				free(str);
				return (NULL);
			}
		}
	}
	return (str);
}

void	expand_ast_env(t_ast *ast)
{
	while (ast)
	{
		ast->str = check_env(ast->str, 0, 1);
		skip_quote_dquote(ast->str);
		ast = ast->next;
	}
}

char	*expand_env_str(char *str)
{
	str = check_env(str, 0, 1);
	skip_quote_dquote(str);
	return (str);
}

bool	check_delimiter(char c)
{
	if (c == '_' || ft_isalnum(c) || c == '?')
		return (true);
	return (false);
}
