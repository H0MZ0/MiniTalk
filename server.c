/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:28:49 by hakader           #+#    #+#             */
/*   Updated: 2025/02/07 13:55:20 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main()
{
	pid_t	get;

	get = getpid();

	printf("PID : -> {%d}\n", get);
	while (1)
	{
		sleep(2);
		printf("send any signal!\n");
	}
	sigaction();
}
