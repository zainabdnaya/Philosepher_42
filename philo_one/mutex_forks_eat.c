/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_forks_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:24:48 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/01 04:27:25 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"


void pickup_forks(t_philo_state *philo)
{
    if (pthread_mutex_lock(&philo->forks[philo->right_fork]) == 0)
    {
        // death(philo);
        display_msg(philo, 4);
    }
    if (pthread_mutex_lock(&philo->forks[philo->left_fork]) == 0)
    {
        // death(philo, 2);
        display_msg(philo, 4);
        philo->status = EAT;
    }
}

void eating_time(t_philo_state *philo)
{
    if (philo->status == EAT)
    {
        pthread_mutex_lock(&philo->is_eating);
        display_msg(philo, 2);
        usleep(1000 * (philo->eat));
        pthread_mutex_unlock(&philo->is_eating);
        philo->last_meal = time_data();
    }
}

void put_down_forks(t_philo_state *philo)
{
    pthread_mutex_unlock(&philo->forks[philo->right_fork]);
    pthread_mutex_unlock(&philo->forks[philo->left_fork]);
    display_msg(philo, 3);
    usleep(philo->sleep * 1000);
}