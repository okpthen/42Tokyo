/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:26:07 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 20:13:16 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	export_error(char *s)
{
	int	i;

	i = 0;
	if ('0' <= *s && *s <= '9')
		return (0);
	while (s[i])
	{
		if (ft_isalnum(s[i]) || s[i] == '_')
			i ++;
		else if (s[i] == '=' && i != 0)
			return (1);
		else if (s[i] == '=' && i == 0)
			return (0);
		else if (s[i] == '+' && s[i + 1] == '=' && i != 0)
			return (2);
		else if (s[i] == '+' && s[i + 1] == '=' && i == 0)
			return (0);
		else
			return (0);
	}
	return (3);
}

int	builtin_export(int ac, char **av)
{
	int	i;
	int	c;

	i = 1;
	if (ac == 1)
	{
		show_env(NULL, 1);
	}
	while (i < ac)
	{
		c = export_error(av[i]);
		if (c == 0)
		{
			write(2, "-bash: export: `", 17);
			write(2, av[i], ft_strlen(av[i]));
			write(2, "': not a valid identifier\n", 27);
			return (1);
		}
		else if (c == 1)
			ft_addenv(av[i], NULL);
		else if (c == 2)
			ft_addenv_str(av[i], NULL);
		i ++;
	}
	return (0);
}
