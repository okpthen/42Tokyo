/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:25:44 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 16:25:47 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_cd(int ac, char **av)
{
	if (ac > 2)
	{
		write(2, "builtin: cd: too many arguments\n", 32);
		return (1);
	}
	if (ac == 1 && chdir(ft_getenv("HOME", NULL)))
		return (1);
	if (ac == 2)
	{
		if (chdir(*(av + 1)) == -1)
		{
			write(2, "-bash: cd: ", 11);
			write(2, *(av + 1), ft_strlen(*(av + 1)));
			write(2, ": ", 2);
			perror("");
			return (1);
		}
	}
	return (0);
}
