/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:22 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/18 10:46:20 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	input_check(char *str)
{
	int	flag;
	int	count;

	flag = 1;
	count = ft_strlen(str);
	if (count != 31)
		return (0);
	while (*str)
	{
		if (flag && *str >= '1' && *str <= '4')
		{
			flag = 0;
		}
		else if (!flag && *str == ' ')
		{
			flag = 1;
		}
		else
		{	
			return (0);
		}
		str ++;
	}
	return (1);
}

// #include<stdio.h>
// int main ()
// {
// 	printf("%d\n",input_check("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"));
// }