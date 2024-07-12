/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:49:15 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 16:47:12 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq(char *path)
{
	t_map	map;
	char	*str;

	if (path == NULL)
		str = standard_input();
	else
		str = read_file(path);
	map = ft_map(str);
	if (map.check == 1)
		ft_solve(map, str);
	else
		ft_putstr_error("map error\n");
	free (str);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_bsq(NULL);
	}
	if (argc > 1)
	{
		while (i < argc)
		{
			ft_bsq(argv[i]);
			if (i != argc -1)
				write (1, "\n", 1);
			i ++;
		}
	}
	return (0);
}
