/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:44:04 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 18:33:09 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str ++;
	}
	return (1);
}

// #include<stdio.h>
// int main(void)
// {
// 	printf ("%d\n",ft_str_is_lowercase("asdfp"));
// 	printf ("%d\n",ft_str_is_lowercase("asdfA"));
// }