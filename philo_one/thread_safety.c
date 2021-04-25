/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safety.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 02:19:43 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/24 02:50:25 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"
#include <stdio.h>

#define BIG 1000000000UL

uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


void *count_to_big(void *arg)
{
    uint32_t i = 0;

    while (i < BIG)
    {
        pthread_mutex_lock(&lock); //thread will wait here until it can get lock witch means it will wait untill the feils is empty for her ti start working 
        counter++;
        i++;
        pthread_mutex_unlock(&lock); //
    }
    return(NULL);
}

int main()
{
    pthread_t t;

    pthread_create(&t,NULL,count_to_big,NULL);
    count_to_big(NULL);
    // count_to_big(NULL);
    pthread_join(t,NULL);
    printf("counter: %u\n",counter);
}
