/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:25:48 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 15:31:04 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_all_n(char *s)
{
	int	i;

	i = 1;
	if (s[0] != '-')
		return (0);
	if (s[1] == 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(int ac, char **av)
{
	int	last_nl;
	int	i;

	i = 1;
	last_nl = 1;
	while (av[i] != NULL && is_all_n(av[i]))
	{
		last_nl = 0;
		i++;
	}
	while (i < ac)
	{
		if (write(1, av[i], ft_strlen(av[i])) == -1)
			return (-1);
		if (av[i + 1] != NULL && av[i][0] != 0)
			if (write(1, " ", 1) == -1)
				return (1);
		i++;
	}
	if (last_nl)
		if (write(1, "\n", 1) == -1)
			return (1);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	return (echo(av));
// }
