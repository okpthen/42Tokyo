/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:26:03 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 15:50:31 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		status_code(int mode, int num, int is_signal);
long	ft_atol(const char *nptr);
int		is_overflow(const char *nptr);

int	is_all_digit(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i] != 0)
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(int ac, char **av)
{
	int	status;

	if (ac > 2)
		return (write(2, "exit\n-bash: exit: too many arguments\n", 37), 1);
	else if (ac == 1)
	{
		write(2, "exit\n", 5);
		status = status_code('r', 0, 0);
		exit(status);
	}
	else
	{
		write(2, "exit\n", 5);
		if (is_all_digit(av[1]) == 0 || is_overflow((av[1])))
		{
			write(2, "bash: exit: ", 12);
			write(2, av[1], ft_strlen(av[1]));
			write(2, ": numeric argument required\n", 28);
			exit(255);
		}
		else
			exit(ft_atol(av[1]) % 256L);
	}
	return (1);
}
