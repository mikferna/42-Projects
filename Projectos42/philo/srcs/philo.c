/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:09:36 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/12 12:17:41 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo(t_rules *rules)
{
	int			i;
	t_philos	*philo;

	i = 0;
	philo = rules->philo;
	rules->start_time = timestamp();
	while (i++ <= rules->nb_philo)
	{
		if (pthread_create(&(philo[i].t_id), NULL, &philosophers, &(philo[i])))
			ft_exit_2("Pthread Error");
		philo[i].last_eat = timestamp();
	}
}

void	*philosophers(void *philo)
{
	
}
