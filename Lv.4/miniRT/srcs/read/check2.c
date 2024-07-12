/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:31:44 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:27 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/read.h"

bool	check_norm(t_vec3 vet3)
{
	if (1 < vet3.x || vet3.x < -1)
		return (false);
	if (1 < vet3.y || vet3.y < -1)
		return (false);
	if (1 < vet3.z || vet3.z < -1)
		return (false);
	if (vet3.x == 0 && vet3.y == 0 && vet3.z == 0)
		return (false);
	return (true);
}

bool	check_fov(double num)
{
	if (num == FOV_ERROR)
		return (false);
	return (true);
}

bool	check_vec3(t_vec3 vec3)
{
	if (vec3.x == VEC_ERROR || vec3.y == VEC_ERROR || vec3.z == VEC_ERROR)
		return (false);
	return (true);
}

bool	check_vec(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(str, ',');
	while (arr[i])
		i ++;
	if (i != 3 || check_double_3ele(arr) == false)
	{
		free_arr(arr);
		return (false);
	}
	free_arr(arr);
	return (true);
}
