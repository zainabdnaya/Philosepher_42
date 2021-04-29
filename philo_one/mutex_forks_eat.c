/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_forks_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:24:48 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/29 02:33:53 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void pickup_forks(t_data *data)
{
    pthread_mutex_lock(&data->forks[data->index]);
    display_msg(data, 4);
    pthread_mutex_lock(&data->forks[(data->index + 1) % data->nbr_philo]);
    display_msg(data, 4);
}

void eating_time(t_data *data)
{
    pthread_mutex_lock(&data->is_eating);
    data->status[data->index] = EAT;
    display_msg(data, 2);
    usleep(1000 * (data->t_eat));
    pthread_mutex_unlock(&data->is_eating);
}

void put_down_forks(t_data *data)
{
    pthread_mutex_unlock(&data->forks[data->index]);
    pthread_mutex_unlock(&data->forks[((data->index + 1) % (data->nbr_philo))]);
    display_msg(data, 3);
    usleep(data->t_sleep * 1000);
    data->status[data->index] = SLEEP;
}