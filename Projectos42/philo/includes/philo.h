/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:06:16 by mikferna          #+#    #+#             */
/*   Updated: 2023/09/15 12:28:15 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philos
{
	int					philo_id;
	int					l_fork_id;
	int					r_fork_id;
	int					n_eat;
	long long			last_eat;
	struct s_rules		*rules;
	pthread_t			t_id;
}	t_philos;

typedef struct s_rules
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					died;
	int					all_ate;
	long long			start_time;
	pthread_mutex_t		forks[200];
	pthread_mutex_t		write;
	pthread_mutex_t		eating;
	t_philos			philo[200];
}	t_rules;

///*-main.c-*/
int			main(int argc, char **argv);

///*-utils.c-*/
void		ft_exit_2(char *str);
int			ft_atoi(const char *str);
long long	get_time(void);
void		action_t_checker(long long time, t_rules *rules);
void		print_actions(t_rules *rules, int id, char *str);

///*-init.c-*/
int			init(t_rules *rules, char **argv);
int			initiate_mutex(t_rules *rules);
int			initiate_philos(t_rules *rules);

///*-philo.c-*/
void		philo(t_rules *rules);
void		*philosophers(void *vphilo);
void		eat_funct(t_philos *philo);
void		terminator(t_rules *r, t_philos *ph);
void		dead_eat_checker(t_rules *r, t_philos *ph);

#endif