/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:58:34 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/26 23:02:23 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv,&tz);

    printf("Seconde : %lu\n",tv.tv_sec);
    printf("Microseconds: %d\n",tv.tv_usec);
    printf("Minutes west of Greenwich: %d\n",tz.tz_minuteswest);
    printf("Daylight Saving Time adjustment: %d\n",tz.tz_dsttime);

    return(0);
}