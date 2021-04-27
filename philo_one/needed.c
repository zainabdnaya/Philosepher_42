/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:44:07 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/26 23:51:55 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosepher.h"

uint64_t    time_data(void)
{
    static struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void    ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (!s)
        return;
    while (s[i])
        write(fd, &s[i++], 1);
}