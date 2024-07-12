/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:07:59 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 18:33:40 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*copy;

	copy = str;
	while (*str)
	{
		if (*str <= 'z' && *str >= 'a')
			*str = *str - 32;
		str++;
	}
	return (copy);
}

// #include<stdio.h>
// int main() {
//     char str[] = "hello, world!";

//     printf("%s\n", str);
//     char *result = ft_strupcase(str);
//     printf("%s\n", result);

//     return 0;
// }