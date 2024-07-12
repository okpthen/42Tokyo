/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:09:19 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/03 15:38:39 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philo_forks(t_philo *philo, pthread_mutex_t *fork, int i, int max)
{
	if (i == 0)
		philo->right = &fork[max - 1];
	else
		philo->right = &fork[i - 1];
	philo->left = &fork[i];
}

void	init_fork(pthread_mutex_t *fork, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i ++;
	}
}

t_philo	*init_philo(t_rule *rule)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	philo = malloc (sizeof(t_philo) * rule->number);
	fork = malloc (sizeof(pthread_mutex_t) * rule->number);
	init_fork(fork, rule->number);
	rule->forks = fork;
	while (i < rule->number)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].rule = rule;
		philo[i].meal_time = 0;
		pthread_mutex_init(&philo[i].meal, NULL);
		philo_forks(&philo[i], fork, i, rule->number);
		philo[i].start = rule->start;
		philo[i].last_meal = rule->start;
		i ++;
	}
	rule->philos = philo;
	return (philo);
}
