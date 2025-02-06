/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:30:26 by hakader           #+#    #+#             */
/*   Updated: 2025/02/06 12:03:03 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	long	numbers;

	i = 0;
	sign = 1;
	numbers = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numbers = numbers * 10 + (str[i++] - 48);
		if ((numbers * sign) < -2147483648 || (numbers * sign) > 2147483647)
			exit (1);
	}
	return (numbers * sign);
}
