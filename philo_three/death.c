/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:31:33 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/19 10:02:38 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void	*count_eat(void *arg)
{
	t_philo_state	*data;

	data = (t_philo_state *)arg;
	while (1)
	{
		sem_wait(data->test);
		sem_wait(data->mtx_death);
		data->idx++;
		if (data->idx >= data->ph_nbr * data->numbr)
		{
			sem_wait(data->msg);
			ft_putstr_fd("\033[31mAT ", 1);
			ft_putnbr_fd(time_data() - data->start, 1);
			ft_putstr_fd(" ms \t\t : Stop Stimulation!\n", 1);
			sem_post(data->philo_dead);
			break ;
		}
		sem_post(data->mtx_death);
		usleep(1000);
	}
	return (data);
}

void	*death(void *dt)
{
	t_philo_state	*data;

	data = (t_philo_state *)dt;
	while (1)
	{
		sem_wait(data->mtx_death);
		if ((time_data() - data->last_meal > data->die) && data->status != EAT)
		{
			sem_wait(data->msg);
			ft_putstr_fd("\033[31mAT ", 1);
			ft_putnbr_fd((int)time_data() - data->start, 1);
			ft_putstr_fd(" ms \t\t :Philosophe ", 1);
			ft_putnbr_fd(data->is_sit_in, 1);
			ft_putstr_fd("  is Death ! \n", 1);
			usleep(500);
			sem_post(data->philo_dead);
			break ;
		}
		usleep(1000);
		sem_post(data->mtx_death);
	}
	return (data);
}

uint64_t	time_data(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}
