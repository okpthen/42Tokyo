/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:28:20 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/09 19:01:02 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a ++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a ++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main (void)
// {
// 	char str[] = "hello";
// 	char dest[20];
// 	ft_strncpy(dest, str, 3);
// 	printf("%s\n", dest);
// 	return 0;
// }