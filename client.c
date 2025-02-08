/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by hakader           #+#    #+#             */
/*   Updated: 2025/02/08 18:55:37 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

int	*char_bin(int c)
{
	int	i;
	int	result;
	int	*bits;

	bits = malloc(sizeof(int) * 8);
	if (!bits)
		return (0);
	i = 7;
	result = 0;
	while (i >= 0)
	{
		bits[i--] = c % 2;
		c = c / 2;
	}
	return (bits);
}

void	send_signals(pid_t pid, char *str)
{
	int	i;
	int	j;
	int	*bits;

	i = 0;
	while (str[i])
	{
		bits = char_bin((int)str[i]);
		i = 0;
		j = 0;
		while (j <= 7)
		{
			if (bits[j] == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			j++;
		}
		while (i <= 7)
			printf("%d", bits[i++]);
		printf("\n");
		exit (1);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;
	int		sig;

	i = 0;
	if (ac == 3)
	{
		pid = (pid_t)ft_atoi(av[1]);
		send_signals(pid, av[2]);
	}
	else
		exit(1);
}
