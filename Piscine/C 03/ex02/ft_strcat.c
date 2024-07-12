/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:33:15 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/09 21:48:31 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*c;

	c = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest ++;
		src ++;
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
// 	strcat(dest, src);
//     printf("strcat %s\n", dest);
// 	char dest1[20] = "Hello, ";
//     char *src1 = "world!";
// 	ft_strcat(dest1, src1);
//     printf("strcat %s\n", dest1);
//     return 0;
// }
