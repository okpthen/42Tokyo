/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:33:08 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 12:10:39 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len_str(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*a;

	a = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (a);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	max_copy;
	unsigned int	d_nb;
	unsigned int	s_nb;

	d_nb = len_str(dest);
	s_nb = len_str(src);
	if (size <= d_nb)
	{
		return (size + s_nb);
	}
	max_copy = size - d_nb -1;
	ft_strncat (dest, src, max_copy);
	return (s_nb + d_nb);
}

// #include <stdio.h>
// #include <string.h>
// int main() 
// {
//     char dest[20] = "Hello, ";
//     char src[] = "world!";
//     // unsigned int dest_size = sizeof(dest) / sizeof(dest[0]);
//     printf("dest = %s, src = %s\n", dest, src);
//     unsigned int result = ft_strlcat(dest, src, 20);
//     printf("dest = %s, src = %s\n", dest, src);
//     printf("length: %u\n", result);
//     return 0;
// }