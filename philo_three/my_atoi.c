/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:08:21 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/15 22:53:06 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

uint64_t time_data(void)
{
    static struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int check_digit(const char *s)
{
    int i;

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

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (!s)
        return;
    while (s[i])
        write(fd, &s[i++], 1);
}

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

static int operation(const char *str, long lenght, int sign)
{
    long r;
    int i;

    r = 0;
    i = 0;
    while (str[lenght] >= 48 && str[lenght] <= 57)
    {
        r = r * 10 + str[lenght] - '0';
        lenght++;
        i++;
    }
    if (i > 19)
    {
        if (sign > 0)
            return (-1);
        else
            return (0);
    }
    return (sign * r);
}

uint64_t my_atoi(const char *str)
{
    long lenght;
    int sign;

    lenght = 0;
    sign = 1;
    while (str[lenght] == ' ' || str[lenght] == '\n' || str[lenght] == '\t' || str[lenght] == '\r' || str[lenght] == '\f' || str[lenght] == '\v')
        lenght++;
    if (str[lenght] == '-' || str[lenght] == '+')
    {
        if (str[lenght] == '-')
        {
            ft_putstr_fd("Error: It should be Positive\n", 1);
            exit(1);
        }
        lenght++;
    }
    return (operation(str, lenght, sign));
}