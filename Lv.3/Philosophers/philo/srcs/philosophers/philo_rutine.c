/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:09:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/06 13:42:38 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	value_rule_end(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->rule->end_m);
	i = philo->rule->end;
	pthread_mutex_unlock(&philo->rule->end_m);
	return (i);
}

void	report_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = get_time();
	philo->meal_time ++;
	pthread_mutex_unlock(&philo->meal);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_philo(philo, FORK);
	pthread_mutex_lock(philo->right);
	print_philo(philo, EAT);
	report_meal(philo);
	while (get_time() - philo->last_meal < philo->rule->eat)
	{
		usleep(100);
		if (check_end(philo))
			break ;
	}
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	*philo_rutine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = arg;
	while (check_end(philo) == 0)
	{
		if (i == 0 && philo->id % 2 == 1)
			philo_eat(philo);
		else if (i == 0 && philo->id % 2 == 0)
		{
			usleep(10000);
			philo_eat(philo);
		}
		else
			philo_eat(philo);
		philo_sleeping(philo);
		i ++;
	}
	return (NULL);
}
