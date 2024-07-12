/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:12:37 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/21 21:13:50 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(long n, int i)
{
	if (i < 16)
		ft_putnbr(n / 16, i +1);
	ft_putchar("0123456789abcdef"[n % 16]);
	return ;
}

void	ft_char(unsigned char *c, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while (i < size && j < 16)
	{
		ft_putchar ("0123456789abcdef"[*c / 16]);
		ft_putchar ("0123456789abcdef"[*c % 16]);
		if ((i % 2) == 1)
			write (1, " ", 1);
		c ++;
		i ++;
		j ++;
	}
	while (j < 16)
	{
		write (1, "  ", 2);
		if ((j % 2) == 1)
			write (1, " ", 1);
		j ++;
	}
	return ;
}

void	ft_putstr(unsigned char *c, unsigned int i, unsigned int size)
{
	int	j;

	j = 0;
	while (i < size && j < 16)
	{
		if (*c >= 32 && *c <= 126)
			write(1, c, 1);
		else
			write(1, ".", 1);
		c ++;
		i ++;
		j ++;
	}
	write(1, "\n", 1);
	return ;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	uintptr_t			address;
	unsigned int		i;
	unsigned char		*c;

	i = 0;
	address = (uintptr_t)addr;
	c = (unsigned char *)addr;
	while (i < size)
	{
		ft_putnbr(address, 0);
		write (1, ": ", 2);
		ft_char(c, i, size);
		ft_putstr(c, i, size);
		i = i +16;
		address = address + 16;
		c = c + 16;
	}
	return (addr);
}

// #include<stdio.h>
// unsigned int	ft_stelen(char *str)
// {
// 	unsigned int i;
// 	i = 0;
// 	while (*str)
// 	{
// 		str ++;
// 		i ++;
// 	}
// 	return (i);
// }
// int main (void)
// {
// 	char *s = "Bonjour les amin ches...c. est ==ß≈ç√ˆø∆∆ˆøˆ¥.avec print";
// 	ft_print_memory(s, 82);
// 	printf("%d",ft_stelen(s));
// 	return 0;
// }