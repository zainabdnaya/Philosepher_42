/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:42:28 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/27 15:09:21 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void check_error(int ac, char **av)
{

	if (ac < 5 || ac > 6)
		handle_errors("Error: Less or more Arguments!\n");
	if (!check_digit(av[1]) || !check_digit(av[2]) || !check_digit(av[3]) || !check_digit(av[4]))
		handle_errors("Error: You should put just Positive Numbers!\n");
	if (ac == 6 && !check_digit(av[5]))
		handle_errors("Error: You should put just Numbers!\n");
	if (my_atoi(av[1]) < 1)
		handle_errors("Error: av[1] > 1 ( u need 2 forks at least to eat)!\n");
	if (my_atoi(av[2]) <= 60 || my_atoi(av[3]) <= 60 || my_atoi(av[4]) <= 60)
		handle_errors("Error: The av[2],av[3],av[4] should be > 60!\n");
	if (ac == 6 && my_atoi(av[5]) <= 0)
		handle_errors("Error: The Round of eating should be > 0!\n");
}

void init_philos(char **av, t_data *data, uint64_t time, unsigned int i)
{
	pthread_mutex_init(data->msg, NULL);
	pthread_mutex_init(data->is_death, NULL);
	pthread_mutex_init(data->philo_dead, NULL);
	time = time_data();
	while (i < data->nbr_philo)
	{
		data->philos[i].is_sit_in = i + 1;
		data->philos[i].right_fork = i;
		data->philos[i].left_fork = (i + 1) % data->nbr_philo;
		data->philos[i].die = data->t_die;
		data->philos[i].eat = data->t_eat;
		data->philos[i].sleep = data->t_sleep;
		data->philos[i].round_eat = data->nbr;
		data->philos[i].numbr = data->nbr;
		data->philos[i].ph_nbr = (unsigned int)my_atoi(av[1]);
		data->philos[i].is_death = data->is_death;
		data->philos[i].mtx_death = data->mtx_death;
		data->philos[i].msg = data->msg;
		data->philos[i].philo_dead = data->philo_dead;
		data->philos[i].start = time;
		data->philos[i].last_meal = time_data();
		i++;
	}
}

void allocate(t_data *data)
{
	data->philos = (t_philo_state *)
		malloc(sizeof(*(data->philos)) * data->nbr_philo);
	if (!data->philos)
		return;
	data->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * (data->nbr_forks));
	if (!data->forks)
		return;
	data->is_death = malloc(sizeof(pthread_mutex_t));
	if (!data->is_death)
		return;
	data->philo_dead = malloc(sizeof(pthread_mutex_t));
	if (!data->philo_dead)
		return;
	data->msg = malloc(sizeof(pthread_mutex_t));
	if (!data->msg)
		return;
}

void initial_data(char **av, t_data *data)
{
	unsigned int i;
	uint64_t time;

	data->nbr_philo = (unsigned int)my_atoi(av[1]);
	data->nbr_forks = (unsigned int)my_atoi(av[1]);
	data->t_die = my_atoi(av[2]);
	data->t_eat = (unsigned int)my_atoi(av[3]);
	data->t_sleep = my_atoi(av[4]);
	if (av[5])
		data->nbr = (unsigned int)my_atoi(av[5]);
	else
		data->nbr = -1;
	allocate(data);
	pthread_mutex_init(&data->mtx_death, NULL);
	i = 0;
	time = 0;
	init_philos(av, data, time, i);
}
