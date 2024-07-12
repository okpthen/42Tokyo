/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:03:20 by kazokada          #+#    #+#             */
/*   Updated: 2024/06/28 22:23:21 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void	set_env(t_env **e)
{
	show_env(e, 0);
	ft_addenv(NULL, e);
	delete_env(NULL, e);
	ft_getenv(NULL, e);
	get_path_in_string(e);
	free_env(e);
	ft_addenv_str(NULL, e);
}

void	free_env(t_env **e)
{
	static t_env	**env;
	t_env			*del;
	t_env			*now;

	if (e)
	{
		env = e;
		return ;
	}
	else
	{
		if (*env == NULL)
			return ;
		now = *env;
		while (now)
		{
			del = now;
			now = now->next;
			free_one_env(del);
		}
	}
}

void	free_one_env(t_env *del)
{
	free(del->key);
	free(del->value);
	free(del);
}

t_env	*creat_env(char *str)
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

t_env	*make_env_lst(char **env)
{
	t_env	*e;
	t_env	*now;
	int		i;

	i = 1;
	e = creat_env(env[0]);
	now = e;
	while (env[i])
	{
		now->next = creat_env(env[i]);
		now = now->next;
		i ++;
	}
	return (e);
}
