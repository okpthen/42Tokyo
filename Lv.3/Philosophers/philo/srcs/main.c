/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:25 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:30 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	start_meal(t_philo *philo, t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->number)
	{
		pthread_create(&philo[i].t_id, NULL, philo_rutine, &philo[i]);
		i ++;
	}
	pthread_create(&rule->grem_reaper, NULL, grem_reaper, rule);
	pthread_create(&rule->finish_meal, NULL, count_meal_time, rule);
	i = 0;
	while (i < rule->number)
	{
		pthread_join(philo[i].t_id, NULL);
		i ++;
	}
	pthread_join(rule->grem_reaper, NULL);
	pthread_join(rule->finish_meal, NULL);
}

void	start_solomeal(t_philo *philo, t_rule *rule)
{
	pthread_create(&philo[0].t_id, NULL, philo_solo, &philo[0]);
	pthread_create(&rule->grem_reaper, NULL, grem_reaper, rule);
	pthread_join(philo[0].t_id, NULL);
	pthread_join(rule->grem_reaper, NULL);
}

int	main(int argc, char **argv)
{
	t_rule	*rule;
	t_philo	*philo;

	if (argc < 5 || 6 < argc)
	{
		printf("input correct arg\n");
		return (0);
	}
	rule = check_input(argv);
	if (rule == NULL)
	{
		printf("input correct arg\n");
		return (0);
	}
	philo = init_philo(rule);
	if (rule->number == 1)
		start_solomeal(philo, rule);
	else
		start_meal(philo, rule);
	free_all(philo, rule);
	return (0);
}
