/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:31:10 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/11 12:04:24 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1 ++;
		s2 ++;
	}
	return (0);
}

// #include<stdio.h>
// int	main ()
// {
// 	char *a = "abd";
// 	char *b = "abdaaaa";
// 	printf ("%d\n", ft_strcmp(a,b));
// 	return 0;
// }