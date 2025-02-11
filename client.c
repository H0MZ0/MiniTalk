/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by hakader           #+#    #+#             */
/*   Updated: 2025/02/11 11:57:52 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

// int	*char_bin(int c)
// {
// 	int	i;
// 	// int	result;
// 	int	*bits;

// 	bits = malloc(sizeof(int) * 8);
// 	if (!bits)
// 		return (0);
// 	i = 7;
// 	// result = 0;
// 	while (i >= 0)
// 	{
// 		bits[i--] = c % 2;
// 		c = c / 2;
// 	}
// 	return (bits);
// }

void	char_bin(unsigned char c, int bits[8])
{
	int	i;

	i = 8;
	while (i--)
		bits[i] = c & 1, c >>= 1;
}

void	send_signals(pid_t pid, char *str)
{
	int	i;
	int	j;
	int	bits[8];

	i = 0;
	while (str[i])
	{
		char_bin(str[i], bits);
		j = 0;
		while (j <= 7)
		{
			if (bits[j] == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = (pid_t)ft_atoi(av[1]);
		send_signals(pid, av[2]);
	}
	return (0);
}
