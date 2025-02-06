/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:06:59 by hakader           #+#    #+#             */
/*   Updated: 2025/02/06 12:04:58 by hakader          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int	pid;
	pid = 0;
	if (ac == 3)
	{
		printf("server killed !\n");
		if (ft_isnum(av[1]) == 1)
			exit (1);
		pid = ft_atoi(av[1]);
		printf("%d\n", pid);
	}
	else 
		exit (1);
}
