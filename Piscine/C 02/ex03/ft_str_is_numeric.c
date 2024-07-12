/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:38:16 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 18:33:04 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str ++;
	}
	return (1);
}

// #include<stdio.h>
// int main(void)
// {
// 	printf ("%d\n",ft_str_is_numeric("0987p"));
// 	printf ("%d\n",ft_str_is_numeric("1234567890"));
// }