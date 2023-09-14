/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:09:36 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/14 15:48:27 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo(t_rules *rules)
{
	int			i;
	t_philos	*philo;

	i = 0;
	philo = rules->philo;
	rules->start_time = get_time();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(philo[i].t_id), NULL, philosophers, &(philo[i])))
			ft_exit_2("Pthread Error");
		philo[i].last_eat = get_time();
		i++;
	}
}

void	*philosophers(void *vphilo)
{
	int			i;
	t_philos	*ph;
	t_rules		*r;

	i = 0;
	ph = (t_philos *)vphilo;
	r = ph->rules;
	//printf("Philo ID -> [%d]\n", ph->philo_id);
	while (!r->died)
	{
		eat_funct(ph);
		if (r->all_ate)
			break ;
		usleep(10000);
	}
	return (NULL);
}

void	eat_funct(t_philos *philo)
{
	t_rules	*r;

	r = philo->rules;
	pthread_mutex_lock(&(r->forks[philo->l_fork_id]));
	print_actions(r, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(r->forks[philo->r_fork_id]));
	print_actions(r, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(r->eating));
	print_actions(r, philo->philo_id, "is eating");
	//usleep(10);
	pthread_mutex_unlock(&(r->eating));
	pthread_mutex_unlock(&(r->forks[philo->l_fork_id]));
	pthread_mutex_unlock(&(r->forks[philo->r_fork_id]));
}
