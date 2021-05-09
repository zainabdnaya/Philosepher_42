/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:46:14 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/09 00:22:21 by zainabdnaya      ###   ########.fr       */
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

    i = 0;
    while (i < data->nbr_philo)
    {
        data->philos[i].pid = fork();
        if (data->philos[i].pid  == 0)
        {
            cycle(&data->philos[i]);
            exit(0);
        }
        else
            return ;
        
        usleep(100);
        i++;
    }
    i = 0 ;
    // while ( i < data->nbr_philo)
            {
                waitpid(-1,NULL,1);
                // i++;
            }
}

int destroy_free(t_data *data)
{   
    int  i = 0;
    sem_unlink("forks");
    sem_unlink("msg");
    sem_unlink("philo_dead");
    sem_unlink("mtx_dead");

    // while(i < data->nbr_philo)
    //         {
    //             kill(data->philos[i].pid,SIGKILL);
    //             i++;
    //         }
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