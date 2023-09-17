/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:41:35 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/14 14:08:00 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init(t_rules *rules, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->died = 0;
	rules->all_ate = 0;
	if (rules->nb_philo > 200 || rules->time_death < 0 || rules->time_eat < 0
		|| rules->time_sleep < 0 || rules->nb_philo < 1)
		return (1);
	if (rules->nb_philo == 1)
		ft_exit_2("0 1 has taken a fork\n0 1 died");
	if (argv[5])
	{
		rules->nb_eat = ft_atoi(argv[5]);
		if (rules->nb_eat <= 0)
			return (1);
	}
	else
		rules->nb_eat = -1;
	if (initiate_mutex(rules))
		ft_exit_2("Error en Mutex");
	initiate_philos(rules);
	return (0);
}

int	initiate_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&rules->write, NULL))
		return (1);
	if (pthread_mutex_init(&rules->eating, NULL))
		return (1);
	return (0);
}

int	initiate_philos(t_rules *rules)
{
	int			i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].l_fork_id = i;
		rules->philo[i].r_fork_id = (i + 1) % rules->nb_philo;
		rules->philo[i].last_eat = 0;
		rules->philo[i].philo_id = i;
		rules->philo[i].rules = rules;
		rules->philo[i].n_eat = 0;
		i++;
	}
	return (0);
}
