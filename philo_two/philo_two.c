/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:06:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/19 11:21:27 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

int	loop(t_philo_state *philo)
{
	int	i;

	i = 0;
	while (i < philo->ph_nbr)
	{
		if (philo->idx >= philo->numbr)
			philo->done++;
		i++;
	}
	if (philo->done == philo->ph_nbr)
	{
		sem_wait(philo->msg);
		philo->time = time_data() - philo->start;
		printf("\033[31mAT %lld ms\t\t: STOP Stimulation! \n", philo->time);
		sem_post(philo->mtx_death);
		sem_post(philo->philo_dead);
		return (1);
	}
	return (0);
}

void	*cycle(void *arg)
{
	t_philo_state	*philo;
	pthread_t		id;

	philo = (t_philo_state *)arg;
	if (pthread_create(&id, NULL, (void *)death, (void *)philo) != 0)
		return ((void *)1);
	pthread_detach(id);
	while (1)
	{
		pickup_forks(philo);
		eating_time(philo);
		put_down_forks(philo);
		if ((philo->numbr != -1))
		{
			sem_wait(philo->mtx_death);
			if (loop(philo) == 1)
				break ;
			usleep(100);
			sem_post(philo->mtx_death);
		}
		display_msg(philo, 1);
	}
	return (arg);
}

void	creat_threads(t_data *data)
{
	unsigned int	i;
	pthread_t		id;
	t_philo_state	*philo;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo = &data->philos[i];
		philo->forks = data->forks;
		philo->mtx_death = data->mtx_death;
		philo->msg = data->msg;
		philo->philo_dead = data->philo_dead;
		pthread_create(&id, NULL, (void *)cycle, (void *)philo);
		pthread_detach(id);
		i++;
	}
}

int	destroy_free(t_data *data)
{
	unsigned int	i;

	sem_unlink("forks");
	sem_unlink("msg");
	sem_unlink("philo_dead");
	sem_unlink("mtx_dead");
	i = 0;
	while (i < data->nbr_philo)
	{
		free_ph(&data->philos);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_error(ac, av);
	initial_data(av, &data);
	initial_sem(&data);
	sem_wait(data.philo_dead);
	creat_threads(&data);
	sem_wait(data.philo_dead);
	destroy_free(&data);
}
