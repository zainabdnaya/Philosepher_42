/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/18 16:43:06 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void	*loop(void *dt)
{
	t_philo_state	*philo;

	philo = (t_philo_state *)dt;
	while (1)
	{
		pthread_mutex_lock(&philo->mtx_death);
		if (philo->idx >= philo->numbr * philo->ph_nbr)
		{
			pthread_mutex_lock(philo->is_death);
			pthread_mutex_lock(philo->msg);
			printf("\033[31mAT %lld ms\t\t: STOP Stimulation!\n",
				time_data() - philo->start);
			pthread_mutex_unlock(&philo->mtx_death);
			pthread_mutex_unlock(philo->philo_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->mtx_death);
		usleep(1000);
	}
	return (philo);
}

void	*cycle(void *arg)
{
	t_philo_state	*philo;
	pthread_t		id;
	pthread_t		ip;

	philo = (t_philo_state *)arg;
	if (pthread_create(&id, NULL, (void *)death, (void *)philo) != 0)
		return ((void *)1);
	pthread_detach(id);
	if (philo->numbr != -1)
	{
		if (pthread_create(&ip, NULL, (void *)loop, (void *)philo) != 0)
			return ((void *)1);
		pthread_detach(ip);
	}
	philo->idx = 0;
	while (1)
	{
		display_msg(philo, 1);
		pickup_forks(philo);
		eating_time(philo);
		put_down_forks(philo);
	}
	return (arg);
}

void	creat_threads(t_data *data)
{
	unsigned int	i;
	pthread_t		id;
	t_philo_state	*philo;

	i = 0;
	while (i < data->nbr_forks)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->nbr_philo)
	{
		philo = &data->philos[i];
		philo->forks = data->forks;
		pthread_create(&id, NULL, (void *)cycle, (void *)philo);
		pthread_detach(id);
		usleep(10);
		i++;
	}
	pthread_mutex_unlock(philo->is_death);
	usleep(100);
}

int	destroy_free(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nbr_forks)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
	pthread_mutex_destroy(data->is_death);
	pthread_mutex_destroy(&data->mtx_death);
	pthread_mutex_destroy(data->msg);
	pthread_mutex_destroy(data->philo_dead);
	free_ph(&data->philos);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_error(ac, av);
	initial_data(av, &data);
	pthread_mutex_lock(data.philo_dead);
	creat_threads(&data);
	pthread_mutex_lock(data.philo_dead);
	destroy_free(&data);
}
