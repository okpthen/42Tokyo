/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_gremreaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:35:18 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/04 12:40:34 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	rule_value(t_rule *rule)
{
	int	i;

	pthread_mutex_lock(&rule->end_m);
	i = rule->end;
	pthread_mutex_unlock(&rule->end_m);
	return (i);
}

void	simulation_end(t_rule *rule)
{
	pthread_mutex_lock(&rule->end_m);
	rule->end = 1;
	pthread_mutex_unlock(&rule->end_m);
}

void	*grem_reaper(void *arg)
{
	int		i;
	long	j;
	t_rule	*rule;

	i = 0;
	rule = arg;
	usleep(10000);
	while (rule_value(rule) == 0)
	{
		pthread_mutex_lock(&rule->philos[i].meal);
		j = rule->philos[i].last_meal;
		pthread_mutex_unlock(&rule->philos[i].meal);
		if (rule->die < (get_time() - j))
		{
			simulation_end(rule);
			printf("%ld %d died\n", get_time() - rule->philos[i].start, i + 1);
			break ;
		}
		i ++;
		if (i == rule->number)
			i = 0;
	}
	return (NULL);
}

void	*count_meal_time(void *arg)
{
	int		i;
	t_rule	*rule;
	int		j;

	rule = arg;
	i = 0;
	if (rule->finish == 0)
		return (NULL);
	usleep(1000);
	while (rule_value(rule) == 0)
	{
		pthread_mutex_lock(&rule->philos[i].meal);
		j = rule->philos[i].meal_time;
		pthread_mutex_unlock(&rule->philos[i].meal);
		if (rule->finish > j)
			continue ;
		i ++;
		if (i == rule->number)
			simulation_end(rule);
	}
	return (NULL);
}
