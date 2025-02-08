/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:28:49 by hakader           #+#    #+#             */
/*   Updated: 2025/02/08 13:26:11 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	po2(int *num)
{
	int	i;
	int	total;
	int	decval;

	i = 7;
	total = 0;
	decval = 1;
	while (i >= 0)
	{
		if (num[i] == 1)
			total += decval;
		decval *= 2;
		i--;
	}
	write(1, &total, 1);
}

void signal_handler(int sig) 
{
	int i = 0;
	int *num;

	printf("{{%d}}\n", sig);
	num = malloc(sizeof(int) * 8);
	while (i <= 7)
	{
		num[i] = sig;
		i++;
	}
	ft_printint(num);
}
int main()
{
	printf("PID : -> {%d}\n", getpid());
	signal(SIGINT, signal_handler);
	while (1)
	{
		pause();
	}
	// printf("\nhello\n");
	// po2(num);
}
