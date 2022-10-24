/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:24:57 by zpalfi            #+#    #+#             */
/*   Updated: 2022/01/26 15:37:01 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd);

static void	ifpositive(int nbr, int fd)
{
	int	aux;
	int	n;

	aux = nbr / 10;
	n = nbr % 10;
	ft_putnbr_fd(aux, fd);
	ft_putchar_fd(n + '0', fd);
}

static void	ifnegative(int nbr, int fd)
{
	int	aux;
	int	n;

	aux = nbr / 10;
	n = (nbr * -1) % 10;
	ft_putnbr_fd(aux, fd);
	ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	int	aux;

	if (nbr == -2147483648)
	{
		aux = -214748364;
		ft_putnbr_fd(aux, fd);
		ft_putchar_fd('8', fd);
	}
	else if (nbr >= 10)
	{
		ifpositive(nbr, fd);
	}
	else if (nbr <= -10)
	{
		ifnegative(nbr, fd);
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((nbr * -1) + '0', fd);
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}
