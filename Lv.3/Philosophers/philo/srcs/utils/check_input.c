/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:50:33 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/03 15:37:58 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

t_rule	*check_input(char **argv)
{
	t_rule	*rule;

	rule = malloc (sizeof(t_rule));
	rule->number = ft_atoi(argv[1]);
	rule->die = ft_atoi(argv[2]);
	rule->eat = ft_atoi(argv[3]);
	rule->sleep = ft_atoi(argv[4]);
	if (argv[5])
		rule->finish = ft_atoi(argv[5]);
	else
		rule->finish = 0;
	if (rule->number < 0 || rule->die < 0 || rule->eat < 0
		|| rule ->sleep < 0 || rule ->finish < 0 || rule->number > PHILO_MAX)
	{
		free(rule);
		return (NULL);
	}
	rule->end = 0;
	pthread_mutex_init(&rule->print, NULL);
	pthread_mutex_init(&rule->end_m, NULL);
	rule->start = get_time();
	return (rule);
}
