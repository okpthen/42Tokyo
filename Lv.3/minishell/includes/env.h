/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:36:25 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/26 16:29:29 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

char	*ft_getenv(char *str, t_env **e);
void	ft_addenv(char *str, t_env **e);
void	show_env(t_env **e, int flag);
void	free_one_env(t_env *del);
void	unset_env(t_env **env, t_env *tmp);
void	delete_env(char *str, t_env **e);
t_env	*creat_env(char *str);
t_env	*make_env_lst(char **env);
void	set_env(t_env **e);
char	*ft_getenv(char *str, t_env **e);
t_env	*make_env_lst(char **env);
void	delete_env(char *str, t_env **e);
void	ft_addenv(char *str, t_env **e);
void	free_env(t_env **env);
char	*ft_getenv(char *str, t_env **e);
t_env	*make_env_lst(char **env);
void	delete_env(char *str, t_env **e);
void	ft_addenv(char *str, t_env **e);
char	**get_path_in_string(t_env **e);
void	ft_addenv_str(char *str, t_env **e);
bool	check_delimiter(char c);
int		check_env_delimiter(char c, int j);

#endif