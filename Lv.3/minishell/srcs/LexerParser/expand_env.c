/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:20:28 by kazokada          #+#    #+#             */
/*   Updated: 2024/06/28 22:40:10 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*transform_env(char *str, int start, int end)
{
	char	*result;
	char	*env;
	char	*tmp;
	int		i;
	int		c;

	i = 0;
	while (str[i])
		i ++;
	c = str[start + end];
	str[start + end] = '\0';
	env = expand_env_one(&str[start]);
	str[start] = '\0';
	str[start + end] = c;
	tmp = ft_strjoin(str, env);
	result = ft_strjoin(tmp, &str[start + end]);
	free(tmp);
	free(env);
	free(str);
	return (result);
}

int	check_env_delimiter(char c, int j)
{
	static int	flag = 0;

	if (j == 1 && '0' <= c && c <= '9')
		flag = 1;
	if (flag == 1 && !('0' <= c && c <= '9'))
	{
		flag = 0;
		return (0);
	}
	if (check_delimiter(c))
		return (1);
	return (0);
}

char	*check_env(char *str, int i, int j)
{
	int	status;

	status = 0;
	while (str[i])
	{
		if ((str[i] == '$' && !(status & ESCAPED))
			&& (str[i] == '$' && !(status & QUOTE)))
		{
			j = 1;
			while (str[i + j] && check_env_delimiter(str[i + j], j))
				j ++;
			if (j > 1)
			{
				if (str[i + 1] == '?')
					j = 2;
				str = transform_env(str, i, j);
				i = -1;
				status = 0;
			}
		}
		else
			status = check_status(str[i], status);
		i ++;
	}
	return (str);
}

char	*expand_env_one(char *str)
{
	char	*env;

	if (ft_strncmp(&str[1], "?", 2) == 0)
		return (ft_itoa(status_code('r', 0, 0)));
	env = ft_getenv(&str[1], NULL);
	if (env == NULL)
		return (ft_strdup(""));
	return (ft_strdup(env));
}

void	skip_quote_dquote(char *str)
{
	int		status;
	char	*start;

	status = 0;
	start = str;
	while (*str)
	{
		if ((status != ESCAPED && *str == '\'')
			|| (status != ESCAPED && *str == '\"')
			|| (status != ESCAPED && *str == '\\'))
		{
			ft_memmove(str, str + 1, ft_strlen(str));
			str = start;
			continue ;
		}
		status = check_status(*str, status);
		str ++;
	}
}
