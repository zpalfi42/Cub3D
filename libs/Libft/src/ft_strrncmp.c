/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:48:05 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/31 13:24:10 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *str, const char *str2, size_t n)
{
	int	i;
	int	l;

	i = ft_strlen(str) - 1;
	l = ft_strlen(str2) - 1;
	while (n > 0)
	{
		if (str[i] == str2[l])
		{
			i--;
			l--;
			n--;
		}
		else
			break ;
	}
	if (n == 0)
		return (0);
	else
		return (1);
}
