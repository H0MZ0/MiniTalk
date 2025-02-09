/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:49 by hakader           #+#    #+#             */
/*   Updated: 2025/02/09 15:12:47 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static int	bits[8] = {0}; // Fixed-size array
	static int	i = 0;
	int			result;
	int j;

	if (sig == SIGUSR1)
		bits[i] = 0;
	else if (sig == SIGUSR2)
		bits[i] = 1;
	i++;
	j = 0;
	if (i == 8)
	{
		result = 0;
		while (j < 8)
			result = result * 2 + bits[j++];
		char c = (char)result;
		write(1, &c, 1);
		i = 0;
	}
}


int	main(void)
{
	printf("use this PID : {%d}\n", getpid());
	
	struct sigaction sig;
	sig.sa_flags = 0;
	sig.sa_handler = sig_handler;

	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	// signal(SIGUSR1, sig_handler);
	// signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
