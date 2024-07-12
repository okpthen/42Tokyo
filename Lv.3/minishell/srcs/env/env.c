/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:26:30 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:44:39 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

char	*ft_getenv(char *str, t_env **e)
{
	static t_env	**env;
	t_env			*tmp;

	if (e)
		env = e;
	if (str == NULL)
		return (NULL);
	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, str) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_addenv_2(char *str, int c, t_env *tmp)
{
	char	*del;

	if (ft_strcmp(str, tmp->key) != 0)
	{
		str[c] = '=';
		tmp->next = creat_env(str);
	}
	else
	{
		del = tmp->value;
		tmp->value = ft_strdup(&str[c +1]);
		free(del);
	}
}

void	ft_addenv(char *str, t_env **e)
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
	while (str[c] != '=')
		c ++;
	str[c] = '\0';
	while (tmp->next && ft_strcmp(str, tmp->key) != 0)
		tmp = tmp->next;
	ft_addenv_2(str, c, tmp);
}

void	show_env(t_env **e, int flag)
{
	static t_env	**env;
	t_env			*tmp;

	if (e)
		env = e;
	else if (e == NULL)
	{
		tmp = *env;
		while (tmp)
		{
			if (flag)
				printf("declare -x ");
			printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
		}
	}
	return ;
}

void	unset_env(t_env **env, t_env *tmp)
{
	t_env	*a;
	t_env	*b;

	a = *env;
	if (*env == tmp)
	{
		*env = tmp->next;
		free_one_env(tmp);
		return ;
	}
	while (a->next != tmp)
		a = a->next;
	b = a->next->next;
	a->next = b;
	free_one_env(tmp);
	return ;
}

// void	delete_env(char *str, t_env **e)
// {
// 	static t_env	**env;
// 	t_env			*tmp;

// 	if (e)
// 		env = e;
// 	if (str == NULL)
// 		return ;
// 	tmp = *env;
// 	while (tmp)
// 	{
// 		if (ft_strcmp(tmp->key, str) == 0)
// 		{
// 			unset_env(env, tmp);
// 			return ;
// 		}
// 		tmp = tmp->next;
// 	}
// }
