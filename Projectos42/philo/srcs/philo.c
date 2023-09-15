/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:09:36 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/15 13:48:01 by mikferna         ###   ########.fr       */
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
		philo[i].last_eat = get_time();
		if (pthread_create(&(philo[i].t_id), NULL, philosophers, &(philo[i])))
			ft_exit_2("Pthread Error");
		i++;
	}
	dead_eat_checker(rules, philo);
	terminator(rules, philo);
}

void	*philosophers(void *vphilo)
{
	t_philos	*ph;
	t_rules		*r;

	ph = (t_philos *)vphilo;
	r = ph->rules;
	if (ph->philo_id % 2)
		usleep(10000);
	while (!r->died)
	{
		eat_funct(ph);
		if (r->all_ate)
			break ;
		print_actions(r, ph->philo_id, "is sleeping");
		action_t_checker(r->time_sleep, r);
		print_actions(r, ph->philo_id, "is thinking");
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
	philo->last_eat = get_time() - r->start_time;
	pthread_mutex_unlock(&(r->eating));
	action_t_checker(r->time_eat, r);
	philo->n_eat += 1;
	pthread_mutex_unlock(&(r->forks[philo->l_fork_id]));
	pthread_mutex_unlock(&(r->forks[philo->r_fork_id]));
}

void	terminator(t_rules *r, t_philos *ph)
{
	int	i;

	i = 0;
	while (i < r->nb_philo)
	{
		pthread_join(ph[i].t_id, NULL);
		i++;
	}
	i = 0;
	while (i < r->nb_philo)
	{
		pthread_mutex_destroy(&r->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&r->eating);
	pthread_mutex_destroy(&r->write);
}

void	dead_eat_checker(t_rules *r, t_philos *ph)
{
	int	i;

	while (!r->all_ate)
	{
		i = 0;
		while (i < r->nb_philo && !r->died)
		{
			pthread_mutex_lock(&r->eating);
			if (ph->last_eat > r->time_death)
			{
				print_actions(r, ph->philo_id, "died");
				r->died = 1;
			}
			pthread_mutex_unlock(&r->eating);
			usleep(100);
			i++;
		}
		if (r->died)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && ph[i].n_eat >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}
