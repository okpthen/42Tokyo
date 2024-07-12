/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:33:13 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/09 21:48:41 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*c;

	c = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && 0 < nb)
	{
		*dest = *src;
		dest ++;
		src ++;
		nb --;
	}
	*dest = '\0';
	return (c);
}

// #include <stdio.h>
// #include <string.h>
// int main() 
// {
//     char dest[20] = "Hello, ";
//     char *src = "world!";
// 	strncat(dest, src, 3);
//     printf("%s\n", dest);
// 	char dest1[20] = "Hello, ";
//     char *src1 = "world!";
// 	ft_strncat(dest1, src1, 10);
//     printf("%s\n", dest1);
//     return 0;
// }
