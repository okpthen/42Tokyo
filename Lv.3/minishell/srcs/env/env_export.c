/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:03:30 by kazokada          #+#    #+#             */
/*   Updated: 2024/06/28 22:30:02 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

t_env	*creat_env_plus(char *str)
{
	int		i;
	t_env	*new;
	char	*tmp;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	tmp = ft_strdup(str);
	tmp[i] = '\0';
	tmp[i - 1] = '\0';
	new = malloc(sizeof(t_env));
	if (!new)
		exit(1);
	new->key = ft_strdup(tmp);
	if (!new->key)
		exit(1);
	new->value = ft_strdup(&tmp[i + 1]);
	if (!new->value)
		exit(1);
	new->next = NULL;
	free(tmp);
	return (new);
}

void	ft_addenv_str_sub(int c, t_env *tmp, char *str)
{
	char	*s;

	if (ft_strcmp(str, tmp->key) != 0)
	{
		str[c] = '+';
		tmp->next = creat_env_plus(str);
	}
	else
	{
		s = ft_strjoin(tmp->value, &str[c + 2]);
		free(tmp->value);
		tmp->value = s;
	}
}

void	ft_addenv_str(char *str, t_env **e)
{
	static t_env	**env;
	t_env			*tmp;
	int				c;

	c = 0;
	if (e)
		env = e;
	tmp = *env;
	if (str == NULL)
		return ;
	while (str[c] != '+')
		c ++;
	str[c] = '\0';
	while (tmp->next && ft_strcmp(str, tmp->key) != 0)
		tmp = tmp->next;
	ft_addenv_str_sub(c, tmp, str);
}
