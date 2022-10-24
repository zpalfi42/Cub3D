/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:17:00 by zpalfi            #+#    #+#             */
/*   Updated: 2022/09/15 15:52:10 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				count;
	long long int	aux;

	count = 1;
	aux = 0;
	while (*str && (*str == ' ' || *str == '\f' || *str == '\n'
			|| *str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			count = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		aux = (aux * 10) + (*str - '0');
		if (aux > INT_MAX && count == 1)
			return (-1);
		if (aux < -INT_MAX && count == -1)
			return (0);
		str++;
	}	
	aux = aux * count;
	return (aux);
}
