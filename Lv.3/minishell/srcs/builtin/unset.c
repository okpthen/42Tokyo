/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:26:15 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 20:11:40 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_unset(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!(ft_isalpha(av[i][0]) || av[i][0] == '_'))
		{
			write(2, "-bash: unset: `", 16);
			write(2, av[i], ft_strlen(av[i]));
			write(2, "': not a valid identifier\n", 26);
		}
		delete_env(av[i++], NULL);
	}
	return (0);
}
