/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:46:14 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/15 11:17:38 by zdnaya           ###   ########.fr       */
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
        sem_wait(philo->is_eating);
        eating_time(philo);
        sem_post(philo->is_eating);
        put_down_forks(philo);
        display_msg(philo, 1);
    }
    return (arg);
}

void creat_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_philo)
    {
        data->philos[i].pid = fork();
        if (data->philos[i].pid == 0)
        {
            cycle(&data->philos[i]);
            exit(0);
        }
        i++;
    }
    i = 0;
    while ( i < data->nbr_philo)
    {
        waitpid(-1, NULL, 1);
        i++;
    }
}

int destroy_free(t_data *data)
{
    int i;
    sem_unlink("forks");
    sem_unlink("msg");
    sem_unlink("philo_dead");
    sem_unlink("mtx_dead");

    i = 0;
    while (i < data->nbr_philo)
    {
        kill(data->philos[i].pid, SIGKILL);
        i++;
    }
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
    sem_wait(data.philo_dead);
    destroy_free(&data);
}