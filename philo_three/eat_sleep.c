/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:51:12 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/15 16:06:36 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void pickup_forks(t_philo_state *philo)
{
    sem_wait(philo->forks);
    sem_wait(philo->forks);
    display_msg(philo, 4);
    display_msg(philo, 4);
}

void eating_time(t_philo_state *philo)
{
    philo->status = EAT;
    usleep(3);
    display_msg(philo, 2);
    philo->last_meal = time_data();
    usleep(1000 * (philo->eat));
    // if (philo->numbr != -1)
    {
        // philo->idx++;
        sem_post(philo->test);
    }
}

void put_down_forks(t_philo_state *philo)
{
    sem_post(philo->forks);
    sem_post(philo->forks);
    display_msg(philo, 3);
    philo->status = SLEEP;
    usleep(philo->sleep * 1000);
}