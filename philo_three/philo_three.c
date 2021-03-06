/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:46:14 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/19 11:19:57 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

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
		display_msg(philo, 1);
	}
	return (arg);
}

void	creat_threads(t_data *data)
{
	unsigned int	i;
	pthread_t		ip;

	if (data->nbr != -1)
	{
		if (pthread_create(&ip, NULL,
				(void *)count_eat, (void *)(data->philos)) != 0)
			return ;
		pthread_detach(ip);
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid == 0)
		{
			cycle(&data->philos[i]);
			exit(0);
		}
		i++;
	}
}

int	destroy_free(t_data *data)
{
	unsigned int	i;

	sem_unlink("forks");
	sem_unlink("test");
	sem_unlink("msg");
	sem_unlink("philo_dead");
	sem_unlink("mtx_dead");
	i = 0;
	while (i < data->nbr_philo)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		free_ph(&data->philos);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_error(ac, av);
	initial_data(av, &data);
	sem_wait(data.philo_dead);
	creat_threads(&data);
	sem_wait(data.philo_dead);
	destroy_free(&data);
}
