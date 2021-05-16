/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:04:22 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/15 23:11:13 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd)
{
    if (n < 0)
    {
        if (n == -2147483648)
            ft_putstr_fd("-2147483648", fd);
        else
        {
            n = n * (-1);
            ft_putchar_fd('-', fd);
            ft_putnbr_fd(n, fd);
        }
    }
    else
    {
        if (n >= 10)
        {
            ft_putnbr_fd(n / 10, fd);
            ft_putchar_fd(n % 10 + '0', fd);
        }
        else
            ft_putchar_fd(n + '0', fd);
    }
}

void display_msg(t_philo_state *data, int w)
{
    sem_wait(data->msg);
    if (w == 1)
    {
        data->time = (int)(time_data() - data->start);
        ft_putstr_fd("\095[94m AT ", 1);
        ft_putnbr_fd(data->time, 1);
        ft_putstr_fd(" ms\t\t:Philosophe ", 1);
        ft_putnbr_fd(data->is_sit_in, 1);
        ft_putstr_fd("is Thinking!\095[0m\n", 1);
        data->status = THINKING;
    }
    else if (w == 2)
    {
        data->time = (int)(time_data() - data->start);
        ft_putstr_fd("\033[93mAT ", 1);
        ft_putnbr_fd(data->time, 1);
        ft_putstr_fd(" ms\t\t:Philosophe ", 1);
        ft_putnbr_fd(data->is_sit_in, 1);
        ft_putstr_fd("is eatining\033[0m \n", 1);
        data->status = EAT;
    }
    else if (w == 3)
    {
        data->time = time_data() - data->start;
        ft_putstr_fd("\033[94mAT ", 1);
        ft_putnbr_fd(data->time, 1);
        ft_putstr_fd(" ms\t\t:Philosophe ", 1);
        ft_putnbr_fd(data->is_sit_in, 1);
        ft_putstr_fd("is sleeping\033[0m\n", 1);
        data->status = SLEEP;
    }
    else if (w == 4)
    {
        data->time = time_data() - data->start;
        usleep(3);
         ft_putstr_fd("\035[94mAT ", 1);
        ft_putnbr_fd(data->time, 1);
        ft_putstr_fd(" ms\t\t:Philosophe ", 1);
        ft_putnbr_fd(data->is_sit_in, 1);
        ft_putstr_fd("  is tacking fork!\035[0m\n", 1);
    }
    sem_post(data->msg);
}

int handle_errors(char const *str)
{
    if (str)
        write(1, str, ft_strlen(str));
    exit(1);
}

void free_ph(t_philo_state **philo)
{
    if (*philo)
    {
        free(*philo);
        *philo = NULL;
    }
    philo = NULL;
}