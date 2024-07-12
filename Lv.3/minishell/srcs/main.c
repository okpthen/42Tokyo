/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:24:52 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 13:57:12 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_all_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == ' ' || (9 <= s[i] && s[i] <= 13))
		{
			i++;
			continue ;
		}
		else
			return (0);
	}
	free(s);
	return (1);
}

void	main_init(char mode)
{
	static int		ori_fd[2];

	if (mode == 'i')
	{
		ori_fd[0] = dup(0);
		ori_fd[1] = dup(1);
	}
	else if (mode == 'c')
	{
		dup2(ori_fd[0], 0);
		dup2(ori_fd[1], 1);
	}
	else if (mode == 'e')
	{
		rl_clear_history();
		free_env(NULL);
		exit (0);
	}
}

int	main(int ac, char **av, char **ap)
{
	t_env	*e;
	char	*str;
	t_cmd	*cmd;

	e = make_env_lst(ap);
	set_env(&e);
	main_init('i');
	while ((void)ac, (void)av, 1)
	{
		str = loop();
		if (str == NULL)
			break ;
		if (is_all_space(str))
			continue ;
		cmd = make_cmd_lst(str);
		if (cmd)
		{
			exec(cmd);
			clear_cmd_lst(cmd);
			main_init('c');
		}
		free(str);
	}
	main_init('e');
}
