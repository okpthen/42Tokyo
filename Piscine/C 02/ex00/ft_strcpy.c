/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:09:53 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/09 18:58:15 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*copy;

	copy = dest;
	while (*src)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	*dest = '\0';
	return (copy);
}

// #include <stdio.h>
// int	main (void)
// {
// 	char str[] = "hello";
// 	char dest[20];
// 	ft_strcpy(dest, str);
// 	printf("%s\n", dest);
// 	return 0;
// }