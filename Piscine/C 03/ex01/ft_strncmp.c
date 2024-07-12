/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:31:24 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 12:04:09 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while ((*s1 != '\0' || *s2 != '\0') && n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 ++;
		s2 ++;
		n--;
	}
	return (0);
}

// #include<stdio.h>
// int	main ()
// {
// 	char *a = "aba";
// 	char *b = "abd";
// 	printf ("%d\n", ft_strncmp(a,b,3));
// 	return 0;
// }