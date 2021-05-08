/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:06:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/08 03:00:46 by zainabdnaya      ###   ########.fr       */
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
    while (1)
    {
        pickup_forks(philo);
        eating_time(philo);
        put_down_forks(philo);
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

    while (i < data->nbr_philo)
    {
        philo = &data->philos[i];
        philo->forks = data->forks;
        philo->mtx_death = data->mtx_death;
        philo->msg = data->msg;
        philo->philo_dead = data->philo_dead;
        philo->start = time_data();
        pthread_create(&id, NULL, (void *)cycle, (void *)philo);
        pthread_detach(id);
        i++;
    }
}

int destroy_free(t_data *data)
{
    if (sem_wait(data->forks) == 0)
        sem_post(data->forks);
    sem_close(data->forks);
    sem_unlink("forks");
    usleep(400);

    // if (sem_wait(data->msg) == 0)
    //     sem_post(data->msg);
    // sem_close(data->msg);
    sem_unlink("msg");
    // usleep(400);

    // if (sem_wait(data->philo_dead) == 0)
    //     sem_post(data->philo_dead);
    // sem_close(data->philo_dead);
    sem_unlink("philo_dead");
    // usleep(400);

    // if (sem_wait(data->mtx_death) == 0)
    //     sem_post(data->mtx_death);
    // sem_close(data->mtx_death);
    sem_unlink("mtx_dead");
    // usleep(400);
    free_ph(&data->philos);
    exit(1);
}

int main(int ac, char **av)
{
    t_data data;

    check_error(ac, av);
    initial_data(av, &data);
    initial_sem(&data);
    sem_wait(data.philo_dead);
    creat_threads(&data);
    sem_wait(data.philo_dead);
    destroy_free(&data);
}