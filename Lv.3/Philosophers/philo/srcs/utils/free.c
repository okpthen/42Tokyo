/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:26 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	free_all(t_philo *philo, t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->number)
	{
		pthread_mutex_destroy(&rule->forks[i]);
		pthread_mutex_destroy(&philo[i].meal);
		i ++;
	}
	pthread_mutex_destroy(&rule->print);
	pthread_mutex_destroy(&rule->end_m);
	free(rule->forks);
	free(philo);
	free(rule);
}
