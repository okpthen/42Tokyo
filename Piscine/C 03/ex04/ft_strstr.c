/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:33:10 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 12:09:27 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		s = str;
		f = to_find;
		while (*f != '\0' && *s == *f)
		{
			s ++;
			f ++;
		}
		if (*f == '\0')
			return (str);
		str ++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main() 
// {
//     char str[] = "Hello, world!";
//     char to_find[] = "world";
//     char *result = ft_strstr(str, to_find);
//     if (result != '\0') {
//         printf("'%s' find %ld in '%s'.\n", to_find, result - str, str);
//     } else {
//         printf("not found\n", to_find, str);
//     }
//     return 0;
// }