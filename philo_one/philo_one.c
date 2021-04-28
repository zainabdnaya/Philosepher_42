/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/28 01:42:29 by zainabdnaya      ###   ########.fr       */
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
int death(t_data *data, int index)
{
    if (time_data() - data->last_meal >= data->t_die)
    {
        printf("\033[31mAT %lld ms\t:\u2620 Philosopher %d is DEATH\n", data->time, index);
        // exit(1);
        return (1);
    }
    return (0);
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
        data->status[index] = THINKING;
        if (data->status[index] == THINKING || data->status[index] == SLEEP)
        {
            data->time = time_data() - data->start[index];
            printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, index);
        }
        if (pthread_mutex_lock(&data->forks[index]) == 0)
        {
            fork_nbr++;
            data->time = time_data() - data->start[index];
            if (data->time > data->t_die)
            {
                printf("\033[31mAT %lld ms\t:\u2620 Philosopher %d is DEATH\n", data->time, index);
                exit(1);
            }
            printf("\033[0;30mAT %lld ms\t\t:The Philosepher \033[31m%d\033[0m take the fork %d\n", data->time, index, fork_nbr);
        }
        if ((pthread_mutex_lock(&data->forks[(index + 1) % data->nbr_philo]) == 0))
        {
            fork_nbr++;
            data->time = time_data() - data->start[index];
            if (data->time > data->t_die)
            {
                printf("\033[31mAT %lld ms\t:\u2620 Philosopher %d is DEATH\n", data->time, index);
                exit(1);
            }
            printf("\033[0;30mAT %lld ms\t\t:The philosepher \033[31m%d\033[0m take the fork %d\n", data->time, index, fork_nbr);
        }
        if (fork_nbr == 2)
        {
            pthread_mutex_lock(&data->is_eating);
            data->time = time_data() - data->start[index];
            data->status[index] = EAT;
            printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", data->time, index);
            usleep(data->t_eat * 1000);
            pthread_mutex_unlock(&data->forks[index]);
            pthread_mutex_unlock(&data->forks[((index + 1) % (data->nbr_philo))]);
            pthread_mutex_unlock(&data->is_eating);
            data->last_meal = time_data();
            printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time, index);
            data->status[index] = SLEEP;
            usleep(data->t_sleep * 1000);
        }
        if (death(data, index) == 1)
            exit(1);
    }
    arg = (void *)data;
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
        if (pthread_create(&data->philo[i], NULL, cycle, (void *)data) != 0)
            return;
        // pthread_detach(data->philo[i]);
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