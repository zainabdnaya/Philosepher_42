/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/29 12:04:21 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void print(t_data *data)
{
    printf("philo_nbt=>%u\n", data->nbr_philo);
    printf("t_die=>%llu\n", data->t_die);
    printf("t_eat=>%llu\n", data->t_eat);
    printf("t_sleep=>%llu\n", data->t_sleep);
    printf("round_eat=>%u\n", data->round_eat);
    puts("philosophe_data:\n");
}

int get_index(t_data *data)
{
    int index;

    index = data->is_sit_in;
    if (index < data->nbr_philo)
        data->is_sit_in++;
    else
    {
        data->status[0] = THINKING;
        data->is_sit_in = 0;
        index = 0;
    }
    return (index);
}

void *cycle(void *arg)
{
    t_data *data;
    int i = 0;

    data = (t_data *)arg;
    while (1)
    {
       display_msg(data, 1);
	   if (pthread_mutex_lock(&data->forks[data->index]) == 0)
	   {
		   death(data, 2);
		   display_msg(data, 4);
	   }
	   if (pthread_mutex_lock(&data->forks[(data->index + 1) % data->nbr_philo]) == 0)
	   {
		   death(data, 2);
		   display_msg(data, 4);
		   data->status[data->index] = EAT;
	   }
		if (data->status[data->index] == EAT && data->fork_nbr == 2)
		{
			pthread_mutex_lock(&data->is_eating);
			display_msg(data, 2);
			usleep(1000 * (data->t_eat));
			pthread_mutex_unlock(&data->is_eating);
			data->last_meal = time_data();
		}
		pthread_mutex_unlock(&data->forks[data->index]);
		pthread_mutex_unlock(&data->forks[((data->index + 1) % (data->nbr_philo))]);
		display_msg(data, 3);
		usleep(data->t_sleep * 1000);
		if (time_data() - data->last_meal >= data->t_die)
		{
			data->time = time_data() - data->start[data->index];
			printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->index + 1);
			exit(1);
		}
	}
	arg = (void *)data;
    return (arg);
}

void creat_threads(t_data *data)
{
    int i;
    pthread_t id;

    i = 0;
    while (i < data->nbr_forks)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {
        data->index = i;
        data->start[data->index] = time_data();
        data->fork_nbr = 0;
        pthread_create(&id, NULL, cycle, (void *)data);
        pthread_detach(id);
        usleep(100);
        i++;
    }
    i = 0;
    // while (i < data->nbr_philo)
    // {
    //     pthread_join(data->philo[i], NULL);
    //     i++;
    // }
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
    while(1)
    {
        
    }
    destroy_mutex(&data);
}