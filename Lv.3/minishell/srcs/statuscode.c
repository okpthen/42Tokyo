/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statuscode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:36:35 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/24 17:42:19 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	status_code(int mode, int num, int is_signal)
{
	static int	status = 0;
	static int	signal;

	if (mode == 'r')
		return (status);
	else if (mode == 'w')
	{
		if (is_signal)
		{
			signal = 1;
			status = num;
		}
		else
		{
			if (signal != 1)
				status = num;
			else
				signal = 0;
		}
		return (status);
	}
	return (status);
}
