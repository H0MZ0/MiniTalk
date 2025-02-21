/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:37:21 by hakader           #+#    #+#             */
/*   Updated: 2025/02/21 10:08:09 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_bin(unsigned char c, int bits[8])
{
	int		i;

	i = 8;
	while (i--)
	{
		bits[i] = c & 1;
		c >>= 1;
	}
}

void	send_bit(pid_t pid, int bit)
{
	if (bit == 1)
	{
		if (kill(pid, SIGUSR1))
		{
			write(2, "\033[31;3minvalid PID\033[0m\n", 24);
			exit(1);
		}
	}
	else if (kill(pid, SIGUSR2))
	{
		write(2, "\033[31;3minvalid PID\033\[0m\n", 24);
		exit(1);
	}
	usleep(150);
}

void	send_signals(pid_t pid, char *str)
{
	int			i;
	int			j;
	int			bits[8];

	i = 0;
	while (str[i])
	{
		char_bin(str[i], bits);
		j = 0;
		while (j < 8)
		{
			send_bit(pid, bits[j]);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac < 3)
	{
		write(1, "\033[31;3mError: <Valid pid> <Message>\033[0m\n", 36);
		exit(1);
	}
	if (ac > 3)
	{
		write(1, "\033[31;3mError: <Valid pid> <Message>\033[0m\n", 37);
		exit(1);
	}
	pid = (pid_t)ft_atoi(av[1]);
	send_signals(pid, av[2]);
	return (0);
}
