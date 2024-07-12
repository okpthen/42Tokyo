/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:09:37 by kazokada          #+#    #+#             */
/*   Updated: 2024/04/17 18:08:23 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int max)
{
	unsigned int	i;

	i = 0;
	while (i < max && s1[i] == s2[i] && s1[i])
		i ++;
	if (i == max)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
