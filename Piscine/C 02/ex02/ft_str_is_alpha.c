/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 08:15:12 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/08 18:32:59 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
			return (0);
		str ++;
	}
	return (1);
}

// #include<stdio.h>
// int main(void)
// {
// 	printf ("%d\n",ft_str_is_alpha("sfffd4"));
// 	printf ("%d\n",ft_str_is_alpha("sffAfd"));
// }