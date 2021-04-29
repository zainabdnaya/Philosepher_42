/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/29 02:47:04 by zainabdnaya      ###   ########.fr       */
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
int death(t_data *data, int w)
{
    if (w == 1)
    {
        if (time_data() - data->last_meal >= data->t_die)
        {
            data->time = time_data() - data->start[data->index];
            printf("\033[31mAT %lld ms\t:\u2620 Philosopher %d is DEATH\n", data->time, data->nbr_philo);
            exit(1);
        }
    }
    if (w == 2)
    {
        if (data->time > data->t_die)
        {
            data->time = time_data() - data->start[data->index];
            printf("\033[31mAT %lld ms\t:\u2620 Philosopher %d is DEATH\n", data->time, data->nbr_philo);
            exit(1);
        }
    }
    pthread_mutex_unlock(&data->mtx_death);
    return (0);
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

               data->fork_nbr = 0;
        if (pthread_create(&id, NULL, cycle, (void *)data) != 0)
            return;
        data->index = i;
        usleep(40);
        i++;
        pthread_detach(id);
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