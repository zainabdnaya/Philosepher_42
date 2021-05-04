/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:06:34 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/04 13:43:59 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void creat_threads(t_data *data)
{
    int i;
    pthread_t id;
    t_philo_state *philo;

    i = 0;
    while (i < data->nbr_forks)
    {
        
        i++;
    }
    i = 0;
    while (i < data->nbr_philo)
    {
        philo = &data->philos[i];
        usleep(10);
        usleep(10);
        pthread_create(&id, NULL, (void *)cycle, (void *)philo);
        pthread_detach(id);
        usleep(10);
        i++;
    }
}

int main(int ac, char **av)
{
    t_data data;

    check_error(ac, av);
    init_data(av, &data);
    creat_threads(&data);
}