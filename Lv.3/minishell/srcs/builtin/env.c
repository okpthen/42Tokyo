/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:26:00 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 16:26:00 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_env(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		write(2, "-bash: env: too many arguments.\n", 32);
		return (2);
	}
	show_env(NULL, 0);
	return (0);
}
