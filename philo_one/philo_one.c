/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/26 02:08:45 by zainabdnaya      ###   ########.fr       */
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
        data->status[0] = THINKING;;
        data->is_sit_in = 0;
        index = 0;
    }
    return (index);
}

void *cycle(void *arg)
{
    t_data *data;
    int index;
    int fork_nbr;
    int i = 0;

    data = (t_data *)arg;
    while (1)
    {
        fork_nbr = 0;

        index = get_index(data);
        if ( data->status[index] == THINKING || data->status[index] == SLEEP)
    {
        printf("\033[94m Philosophe %d is Thinking!\n\033[0m",index);
        data->status[index] = THINKING;
    }
        if ( data->status[index] == THINKING && pthread_mutex_lock(&data->forks[index]) == 0)
        {
            fork_nbr++;
            printf("The Philosepher \033[31m%d\033[0m take the fork %d\n",index, fork_nbr);
        }
        if (data->status[index] == THINKING &&(pthread_mutex_lock(&data->forks[(index + 1) % data->nbr_philo]) == 0))
        {
            fork_nbr++;
            printf("The philosepher \033[31m%d\033[0m take the fork %d\n",index, fork_nbr);
        }
        if(fork_nbr == 2 )
        {
            data->status[index] = EAT;
            printf("\033[33m Philosopher %d is eating \n\033[0m",index);
            usleep(data->t_eat * 1000);
            pthread_mutex_unlock(&data->forks[index]);
            pthread_mutex_unlock(&data->forks[((index + 1) % (data->nbr_philo))]);
            printf("\033[33m Philosopher %d is sleeping \n\033[0m",index);
            data->status[index] =  SLEEP ;
            usleep(data->t_sleep * 1000);
            // data->status[index] = THINKING;
        }
    }
    arg = (void *)data;
    // cycle(arg);
    return (arg);
}

void creat_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_forks)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {
        pthread_create(&data->philo[i], NULL, cycle, (void *)data);
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {

        pthread_join(data->philo[i], NULL);

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
    destroy_mutex(&data);
}