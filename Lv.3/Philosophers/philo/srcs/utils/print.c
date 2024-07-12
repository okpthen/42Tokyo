/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:36:40 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:28 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	print_philo(t_philo *philo, int i)
{
	long	time;

	pthread_mutex_lock(&philo->rule->print);
	pthread_mutex_lock(&philo->rule->end_m);
	if (philo->rule->end == 1)
	{
		pthread_mutex_unlock(&philo->rule->end_m);
		pthread_mutex_unlock(&philo->rule->print);
		return ;
	}
	time = get_time() - philo->start;
	pthread_mutex_unlock(&philo->rule->end_m);
	if (i == FORK)
		printf(MES_FORK, time, philo->id);
	else if (i == THINK)
		printf(MES_THINK, time, philo->id);
	else if (i == SLEEP)
		printf(MES_SLEEP, time, philo->id);
	else if (i == EAT)
	{
		printf(MES_FORK, time, philo->id);
		printf(MES_EAT, time, philo->id);
	}
	pthread_mutex_unlock(&philo->rule->print);
}
