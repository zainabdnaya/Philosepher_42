/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:44:07 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/17 12:04:46 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

uint64_t	time_data(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	check_digit(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
