/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:51:30 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 18:35:05 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < 'A' || *str > 'Z')
			return (0);
		str ++;
	}
	return (1);
}

// #include<stdio.h>
// int main(void)
// {
// 	printf ("%d\n",ft_str_is_uppercase("asdfp"));
// 	printf ("%d\n",ft_str_is_uppercase("A"));
// }