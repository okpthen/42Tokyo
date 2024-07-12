/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisaku <ykisaku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 08:31:28 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 13:09:18 by ykisaku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	ft_putline(char a, char b, char c, int x)
{
	int	k;

	k = 0;
	if (x >= 1)
		ft_putchar(a);
	while (k < x - 2)
	{
		ft_putchar(b);
		k++;
	}
	if (x >= 2)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
	{
		ft_putstr("error\n");
		return ;
	}
	if (y >= 1)
		ft_putline('o', '-', 'o', x);
	while (i < y - 2)
	{
		ft_putline('|', ' ', '|', x);
		i++;
	}
	if (y >= 2)
		ft_putline('o', '-', 'o', x);
}
