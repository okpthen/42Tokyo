/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:46:11 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/14 20:56:48 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_check(char *str)

{
	if (*str == '\0')
		return (1);
	if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
		return (1);
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
}

void	ft_strupcase(char *str)
{
	if ((*str >= 'a' && *str <= 'z'))
	{
		*str = *str - 32;
	}
}

void	ft_strlowcase(char *str)
{
	if ((*str >= 'A' && *str <= 'Z'))
	{
			*str = *str + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*c;

	c = str;
	if ((*str >= 'a' && *str <= 'z'))
		*str = *str - 32;
	while (*str != '\0')
	{
		if (ft_str_check(str) == 1)
		{
			str++;
			ft_strlowcase(str);
		}
		else
		{
			str++;
			ft_strupcase(str);
		}
	}
	return (c);
}

// #include <stdio.h>
// int main() {
//     char input[100] = "he42llo -bwosfrl-d";
// 	ft_strcapitalize(input);
// 	printf("%s\n", input);
//     return 0;
// }
