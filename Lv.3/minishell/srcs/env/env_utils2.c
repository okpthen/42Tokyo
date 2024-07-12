/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:02:12 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:27:54 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

int	count_env(t_env **e)
{
	t_env	*tmp;
	int		i;

	tmp = *e;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	get_path_strcat(char **ret, t_env *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		ret[i] = (char *)malloc(sizeof (char) * (ft_strlen(tmp->key)
					+ ft_strlen(tmp->value) + 2));
		ft_strlcpy(ret[i], tmp->key, (ft_strlen(tmp->key)
				+ ft_strlen(tmp->value) + 2));
		ft_strlcat(ret[i], "=", (ft_strlen(tmp->key)
				+ ft_strlen(tmp->value) + 2));
		ft_strlcat(ret[i], tmp->value, (ft_strlen(tmp->key)
				+ ft_strlen(tmp->value) + 2));
		tmp = tmp->next;
		i++;
	}
	ret[i] = NULL;
}

char	**get_path_in_string(t_env **e)
{
	static t_env	**env;
	t_env			*tmp;
	char			**ret;

	if (e)
	{
		env = e;
		return (NULL);
	}
	else
	{
		ret = (char **)malloc(sizeof (char *) * (count_env(env) + 1));
		if (ret == NULL)
			exit(1);
		tmp = *env;
		get_path_strcat(ret, tmp);
	}
	return (ret);
}

void	delete_env(char *str, t_env **e)
{
	static t_env	**env;
	t_env			*tmp;

	if (e)
		env = e;
	if (str == NULL)
		return ;
	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, str) == 0)
		{
			unset_env(env, tmp);
			return ;
		}
		tmp = tmp->next;
	}
}
