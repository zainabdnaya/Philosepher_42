/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:51:12 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/19 10:19:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void	pickup_forks(t_philo_state *philo)
{
	sem_wait(philo->forks);
	sem_wait(philo->forks);
	display_msg(philo, 4);
	display_msg(philo, 4);
}

void	eating_time(t_philo_state *philo)
{
	philo->status = EAT;
	display_msg(philo, 2);
	philo->last_meal = time_data();
	if (philo->numbr != -1)
	{
		philo->done++;
		sem_post(philo->test);
	}
	usleep(1000 * (philo->eat));
}

void	put_down_forks(t_philo_state *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
	display_msg(philo, 3);
	philo->status = SLEEP;
	usleep(philo->sleep * 1000);
}

int	handle_errors(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	exit(1);
}

void	free_ph(t_philo_state **philo)
{
	if (*philo)
	{
		free(*philo);
		*philo = NULL;
	}
	philo = NULL;
}
