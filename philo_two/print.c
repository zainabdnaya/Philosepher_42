/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:57:33 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/18 18:18:21 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

uint64_t	time_data(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	display_msg1(t_philo_state *data, int w)
{
	if (w == 3)
	{
		data->time = time_data() - data->start;
		printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n",
			data->time, data->is_sit_in);
		usleep(3);
		data->status = SLEEP;
	}
	else if (w == 4)
	{
		data->time = time_data() - data->start;
		usleep(3);
		printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m taking the FORK \n",
			data->time, data->is_sit_in);
	}
}

void	display_msg(t_philo_state *data, int w)
{
	sem_wait(data->msg);
	if (w == 1)
	{
		data->time = time_data() - data->start;
		printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n",
			data->time, data->is_sit_in);
		usleep(3);
		data->status = THINKING;
	}
	else if (w == 2)
	{
		printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n",
			time_data() - data->start, data->is_sit_in);
		usleep(3);
		data->status = EAT;
	}
	else
		display_msg1(data, w);
	sem_post(data->msg);
}

int	handle_errors(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
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
