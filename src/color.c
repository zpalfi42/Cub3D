/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:43:38 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/10 14:19:41 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char *c, int color, int i, int j)
{
	char	*cr;

	cr = malloc(sizeof(char) * 4);
	while (color != 0 && c[++i] != '\0')
	{
		if (c[i] == ',')
		{
			if (color == 0)
				break ;
			else
				color--;
		}
	}
	while (c[++i] != '\0' && c[i] != '\n')
	{
		if (c[i] == ',')
			break ;
		cr[j] = c[i];
		j++;
	}
	cr[j] = '\0';
	i = ft_atoi(cr);
	free(cr);
	return (i);
}
