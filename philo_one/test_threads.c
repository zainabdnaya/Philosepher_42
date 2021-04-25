/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:05:17 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/24 02:14:54 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"
#include <unistd.h>
#include <stdio.h>

void *myturn(void *arg)
{
    int *iptr;

    iptr = (int *)malloc(sizeof(int));
    *iptr = 3;
    int i = 0;
    while(i < 5)
    {
        sleep(1);
        printf("for %d and %d My Turn!\n", i,*iptr);
        (*iptr)++;
        i++;
    }
    return(iptr);
}

void yourturn()
{
    int i = 0;
    while(i < 3)
    {
        sleep(1);
        printf("for %d Your Turn!\n",i);
        i++;
    }
}
int main()
{
    pthread_t newthread;
    int *v;
    pthread_create(&newthread, NULL ,myturn, NULL); // function create thread
    // myturn();
    yourturn();
    pthread_join(newthread, (void *)&v); //it will wait until specific thread finishe runing
    printf("V ==>%d\n",*v);// the second argument in join it's the return value of thread function it's an adress 
    return (0);
}
