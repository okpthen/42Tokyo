/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:22:22 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/12 21:52:08 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str ++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	ft_putstr(argv[0]);
	write(1, "\n", 1);
	(void)argc;
	return (0);
}
