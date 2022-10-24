/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:43:08 by zpalfi            #+#    #+#             */
/*   Updated: 2022/02/10 14:10:30 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = ft_strlen(s);
	d = (char *)s;
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			d += i;
			return (d);
		}
		i--;
	}
	return (NULL);
}
