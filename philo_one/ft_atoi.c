/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:56:53 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/24 20:34:29 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

static int	operation(const char *str, long lenght, int sign)
{
	long		r;
	int			i;

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

uint64_t			my_atoi(const char *str)
{
	long		lenght;
	int			sign;

	lenght = 0;
	sign = 1;
	while (str[lenght] == ' ' || str[lenght] == '\n' || str[lenght] == '\t'
			|| str[lenght] == '\r' || str[lenght] == '\f'
			|| str[lenght] == '\v')
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
