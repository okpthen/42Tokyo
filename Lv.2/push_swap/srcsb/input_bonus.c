/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:03:09 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/02 16:31:33 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_stelen(char *dest)
{
	int	count;

	count = 0;
	while (dest[count])
		count ++;
	return (count);
}

char	*ft_strcat(char *dest, char *src, int size)
{
	char	*new;
	int		c;
	int		dest_size;

	c = 0;
	dest_size = ft_stelen(dest);
	new = malloc (dest_size + size + 1);
	while (c < dest_size)
	{
		new[c] = dest[c];
		c ++;
	}
	while (c < size + dest_size)
	{
		new[c] = *src;
		src ++;
		c ++;
	}
	new[c] = '\0';
	free(dest);
	return (new);
}

char	*standard_input(void)
{
	char	buf[1025];
	int		size;
	char	*result;
	char	*copy;

	size = 1;
	result = malloc(1);
	if (result == NULL)
		return (NULL);
	result [0] = '\0';
	copy = result;
	while (size > 0)
	{
		size = read(0, buf, 1024);
		buf[size] = '\0';
		result = ft_strcat(result, buf, size);
		if (result == NULL)
		{
			free(copy);
			return (NULL);
		}
	}
	return (result);
}
