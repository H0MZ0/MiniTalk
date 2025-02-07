/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:28:49 by hakader           #+#    #+#             */
/*   Updated: 2025/02/07 19:31:13 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	po2(int *num)
{
	int	i;

	i = 0;
	while (i <= 7)
	{

	}
}

int main()
{
	pid_t	get;

	get = getpid();

	printf("PID : -> {%d}\n", get);
	signal();
	
	while (1)
	{
		sleep(2);
		printf("send any signal!\n");
	}
	// sigaction();
}
