/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/25 03:14:19 by zainabdnaya      ###   ########.fr       */
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
            data->is_sit_in = 0;
            index = 0;
        }   
    return(index);
}

void    *cycle(void *arg)
{
    t_data  *data;
       int  index;
       int  fork_nbr;

    data = (t_data *)arg;
    index = get_index(data);
    fork_nbr = 0;

    // printf("index==>%d\n",index);
    if (pthread_mutex_lock(&data->forks[index]) == 0)
    {
        fork_nbr++;
        printf("The philosepher %d take the fork %d\n",data->is_sit_in,fork_nbr);
    }
    if (pthread_mutex_lock(&data->forks[((index + 1) % (data->nbr_philo))]) == 0)
    {
        fork_nbr++;
        printf("The philosepher %d take the fork %d\n",index,fork_nbr);
    }
    if ( fork_nbr == 2)
    {
        data->is_eating = 1;
        printf("Philosopher %d start eating \n",data->is_sit_in);
        usleep(data->t_eat * 1000);
        pthread_mutex_unlock(&data->forks[index]);
        pthread_mutex_unlock(&data->forks[((index + 1) % (data->nbr_philo))]);
        data->is_sleeping = 1;
        printf("Philosopher %d is sleeping \n",data->is_sit_in);
        usleep(data->t_sleep * 1000);
    }
    if ( data->is_thinking == 1)
            printf("The philosophe %d is Thinking!\n",data->is_sit_in);

    return(arg);
}

void    creat_threads(t_data *data)
{
    int i;
    
    i = 0;
    while( i < data->nbr_forks)
    {
        pthread_mutex_init(data->forks,NULL);
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {
        // puts("here");
        pthread_create(&data->philo[i], NULL,cycle ,(void *)data);
        i++;
    }
}


int main(int ac, char **av)
{
    t_data data;
    pthread_t test;

    initial_data(ac, av, &data);
    creat_threads(&data);
    
}