/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:30:31 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:33 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

t_rgb	ato_rgb(char *str)
{
	char	**arr;
	t_rgb	rgb;
	int		i;

	i = 0;
	arr = ft_split(str, ',');
	while (arr[i])
		i ++;
	if (i != 3 || (i == 3 && arr[2][0] == '\n'))
	{
		rgb.b = COLER_ERROR;
		rgb.g = COLER_ERROR;
		rgb.r = COLER_ERROR;
		free_arr(arr);
		return (rgb);
	}
	rgb.r = ato_color(arr[0]);
	rgb.g = ato_color(arr[1]);
	rgb.b = ato_color(arr[2]);
	free_arr(arr);
	return (rgb);
}
