/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/01 04:30:07 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void *cycle(void *arg)
{
	t_philo_state *philo;
    pthread_t id;

	philo = (t_philo_state *)arg;
    pthread_create(&id, NULL, (void *)death, (void *)philo);
    pthread_detach(id);
    usleep(10);
	while (1)
	{
        display_msg(philo,1);
        pickup_forks(philo);
        eating_time(philo);
        put_down_forks(philo);
        usleep(100);
    }
	arg = (void *)philo;
	return (arg);
}

void creat_threads(t_data *data)
{
    int i;
    pthread_t id;
    t_philo_state *philo;

    i = 0;
    while( i < data->nbr_forks )
    {
        pthread_mutex_init(&data->forks[i],NULL);
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {
        philo = data->philos[i];
        philo->forks = data->forks;
        pthread_create(&id, NULL, (void *)cycle, (void *)philo);
        pthread_detach(id);
        usleep(10);
        i++;
    }
}

void destroy_mutex(t_data *data)
{
	int i;
 
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_data data;
	pthread_t test;

	initial_data(ac, av, &data);
	creat_threads(&data);
	while (!dies)
	{

        // printf("[%i]\n",dies);
	}
	// destroy_mutex(&data);
}