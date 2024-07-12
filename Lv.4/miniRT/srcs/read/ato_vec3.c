/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ato_vec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:31:01 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:32 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

bool	check_double_3ele(char **arr)
{
	if (check_double(arr[0]) == true && check_double(arr[1]) == true
		&&check_double(arr[2]) == true)
		return (true);
	return (false);
}

t_vec3	ato_vec3(char *str)
{
	char	**arr;
	t_vec3	vec;
	int		i;

	i = 0;
	arr = ft_split(str, ',');
	while (arr[i])
		i ++;
	if (i != 3 || check_double_3ele(arr) == false)
	{
		vec.x = VEC_ERROR;
		vec.y = VEC_ERROR;
		vec.z = VEC_ERROR;
		free_arr(arr);
		return (vec);
	}
	vec.x = ft_atod(arr[0]);
	vec.y = ft_atod(arr[1]);
	vec.z = ft_atod(arr[2]);
	free_arr(arr);
	return (vec);
}
