/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:18:42 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/13 19:08:45 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	char	*p;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i ++;
	copy = malloc (i +1);
	if (copy == NULL)
		return (NULL);
	p = copy;
	while (*src)
	{
		*copy = *src;
		src ++;
		copy ++;
	}
	*copy = '\0';
	return (p);
}

// #include <stdio.h>
// int main() 
// {
//     char *src = "Leagu of Legends";
//     char *copy = ft_strdup(src);

//     if (copy != NULL) 
// 	{
//         printf("Original %s\n", src);
//         printf("Copied %s\n", copy);
//         free(copy);
//     }
// 	else
// 	{
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }