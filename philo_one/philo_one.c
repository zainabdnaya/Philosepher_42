/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/29 03:23:24 by zainabdnaya      ###   ########.fr       */
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
       pickup_forks(data);
       eating_time(data);
       put_down_forks(data);
       death(data, 1);
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