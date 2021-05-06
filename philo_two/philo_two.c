/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:06:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/06 00:59:25 by zainabdnaya      ###   ########.fr       */
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
    while (1)
    {
        pickup_forks(philo);
        eating_time(philo);
        put_down_forks(philo);
        display_msg(philo, 1);
    }
    sem_post(philo->is_death);
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
        usleep(10);
        philo->forks = data->forks;
        usleep(10);
        pthread_create(&id, NULL, (void *)cycle, (void *)philo);
        pthread_detach(id);
        usleep(10);
        i++;
    }
}

int destroy_free(t_data *data)
{
    sem_close(data->forks);
    sem_unlink("fork");
    sem_close(data->is_death);
    sem_unlink("is_death");
    sem_close(data->mtx_death);
    sem_unlink("mtx_death");
    sem_close(data->msg);
    sem_unlink("msg");
    sem_close(data->is_eating);
    sem_unlink("is_eating");
    sem_close(data->philo_dead);
    sem_unlink("philo_dead");
    free_ph(&data->philos);
    return (1);
}

int main(int ac, char **av)
{
    t_data data;

    check_error(ac, av);
    initial_data(av, &data);
    sem_wait(data.philo_dead);
    creat_threads(&data);
    // while(1)
    // {

    // }
    sem_wait(data.philo_dead);
    sem_post(data.philo_dead);
    destroy_free(&data);
}