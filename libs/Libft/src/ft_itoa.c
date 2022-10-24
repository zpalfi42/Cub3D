/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:32:38 by zpalfi            #+#    #+#             */
/*   Updated: 2022/01/19 15:44:20 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_is_negative(int *n, unsigned int *m, size_t *len)
{
	if (*n <= 0)
	{
		*m = (*n) * (-1);
		(*len)++;
	}
}

static char	*ft_strrev(char *s)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*p;
	size_t			i;
	size_t			len;
	unsigned int	m;

	i = 0;
	len = 0;
	m = n;
	ft_is_negative(&n, &m, &len);
	len += ft_intlen(n);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if (n == 0)
		p[i++] = '0';
	while (m)
	{
		p[i++] = (m % 10) + '0';
		m = m / 10;
	}
	if (n < 0)
		p[i++] = '-';
	p[i] = 0;
	return (ft_strrev(p));
}
