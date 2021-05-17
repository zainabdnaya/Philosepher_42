/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/17 02:46:37 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void *cycle(void *arg)
{
    t_philo_state *philo;
    pthread_t id;

    philo = (t_philo_state *)arg;
    if (pthread_create(&id, NULL, (void *)death, (void *)philo) != 0)
        return ((void *)1);
    pthread_detach(id);
    usleep(10);
    int i;
    while (1)
    {
        pickup_forks(philo);
        eating_time(philo);
        put_down_forks(philo);
        if ((philo->numbr != -1))
        {
            pthread_mutex_lock(&philo->mtx_death);

            i = 0;
            while (i < philo->ph_nbr)
            {
                if (philo->idx > philo->numbr)
                    philo->done++;
                i++;
            }
            if (philo->done == philo->ph_nbr)
            {
                pthread_mutex_lock(philo->is_death);
                pthread_mutex_lock(&philo->msg);
                usleep(3);
                printf("\033[31mAT %lld ms\t\t: STOP Stimulation! \n", time_data() - philo->start);
                pthread_mutex_unlock(&philo->mtx_death);
                pthread_mutex_unlock(philo->philo_dead);
                break;
            }
            usleep(100);
            pthread_mutex_unlock(&philo->mtx_death);
        }
        display_msg(philo, 1);
    }
    return (arg);
}

void creat_threads(t_data *data)
{
    int i;
    pthread_t id;
    t_philo_state *philo;

    i = 0;
    while (i < data->nbr_forks)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
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
        usleep(10);
        i++;
    }
    usleep(100);
    pthread_mutex_unlock(philo->is_death);
}

int destroy_free(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_forks)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    free(data->forks);
    data->forks = NULL;
    if (data->forks)
    {
        pthread_mutex_destroy(&data->mtx_death);
        pthread_mutex_destroy(&data->msg);
        pthread_mutex_destroy(&data->is_eating);
        pthread_mutex_destroy(data->philo_dead);
        free_ph(&data->philos);
    }
    return (1);
}

int main(int ac, char **av)
{
    t_data data;

    check_error(ac, av);
    initial_data(ac, av, &data);
    pthread_mutex_lock(data.philo_dead);
    creat_threads(&data);
    pthread_mutex_lock(data.philo_dead);
    destroy_free(&data);
}