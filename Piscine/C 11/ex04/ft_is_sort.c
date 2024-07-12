/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:14:47 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/19 19:02:59 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while (i < length - 1 && flag)
	{
		if (f(tab[i], tab[i +1]) > 0)
			flag = 0;
		i ++;
	}
	if (flag == 0)
	{
		flag = 1;
		i = 0;
		while (i < length -1 && flag)
		{
			if (f(tab[i], tab[i +1]) < 0)
				return (0);
			i ++;
		}
	}
	return (flag);
}
