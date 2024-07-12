/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:03:14 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/19 18:47:59 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i ++;
	}
	return (0);
}

// #include<stdio.h>
// int is_not_empty(char *str)
// {
// 	if (str[0] == '\0')
// 		return 1;
// 	return 0;
// }
// int main() {
//     char *strings[] = {"Hello", "aa", "World", "ast"};

//     int result = ft_any(strings, &is_not_empty);

//     if (result) {
//         printf("At least one non-empty string found.\n");
//     } else {
//         printf("No non-empty strings found.\n");
//     }
//     return 0;
// }