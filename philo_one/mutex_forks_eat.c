/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_forks_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:24:48 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/03 15:21:46 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"


void pickup_forks(t_philo_state *philo)
{
    if (pthread_mutex_lock(&philo->forks[philo->right_fork]) == 0)
        display_msg(philo, 4);
    if (pthread_mutex_lock(&philo->forks[philo->left_fork]) == 0)
        display_msg(philo, 4);
}

void eating_time(t_philo_state *philo)
{
    philo->status = EAT;
    // usleep(5);
    pthread_mutex_lock(&philo->is_eating);
    display_msg(philo, 2);
    philo->last_meal = time_data();
    usleep(1000 * (philo->eat));
    if (philo->numbr != -1)
        philo->idx++;
    pthread_mutex_unlock(&philo->is_eating);
    }

void put_down_forks(t_philo_state *philo)
{
    pthread_mutex_unlock(&philo->forks[philo->right_fork]);
    pthread_mutex_unlock(&philo->forks[philo->left_fork]);
    // usleep(5);
    display_msg(philo, 3);
    usleep(philo->sleep * 1000);
}