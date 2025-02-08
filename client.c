/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:06:59 by hakader           #+#    #+#             */
/*   Updated: 2025/02/08 13:22:10 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	*conchar(char c)
{
	int	i;
	int	j;
	int	*bits;

	i = 7;
	j = 0;
	bits = malloc(sizeof(int) * 8);
	while (i >= 0)
		bits[j++] = (c >> i--) & 1;
	return (bits);
}


void	send_bits(pid_t pid, int *bits)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (bits[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		*bits;
	int		i;

	if (ac == 3)
	{
		if (ft_isnum(av[1]) == 1)
			exit (1);
		pid = ft_atoi(av[1]);
		if (pid < 0)
		{
			printf("invalid pid\n");
			exit (1);
		}
		int j = 0;
		while (av[2][j])
		{
			i = 0;
			bits = conchar(av[2][j++]);
			send_bits(pid, bits);
			ft_printint(bits);
		}
	}
	else 
		exit (1);
}
