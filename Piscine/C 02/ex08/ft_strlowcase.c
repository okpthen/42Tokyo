/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:42:32 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 18:34:39 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*copy;

	copy = str;
	while (*str)
	{
		if (*str <= 'Z' && *str >= 'A')
			*str = *str + 32;
		str++;
	}
	return (copy);
}

// #include<stdio.h>
// int main() {
//     char str[] = "HELLO, world!";

//     printf("%s\n", str);
//     char *result = ft_strlowcase(str);
//     printf("%s\n", result);

//     return 0;
// }