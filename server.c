/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:49 by hakader           #+#    #+#             */
/*   Updated: 2025/02/08 17:22:01 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    sig_handler(int sig)
{
    static int *bits;
    static int i;
    int result;

    i = 0;
    if (sig == SIGUSR1)
        bits[i] = 0;
    else
        bits[i] = 1;
    i++;
    result = 0;
    if (i == 8)
    {
        i = 0;
        while (i <= 7)
            result *= 2 + bits[i++];
        char c = (char)result;
        write (1, &c, 1);
    }
}

int main()
{
    printf("use this PID : {%d}", getpid());
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    while (1)
        pause();
}
