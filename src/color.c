/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:43:38 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 16:46:35 by zpalfi           ###   ########.fr       */
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

int	color_checker(char *c, int i, int j, int k)
{
	if (ft_strlen(c) > 12)
	{
		printf("Invalid color!\n");
		return (1);
	}
	while (c[++i] != '\0' && c[i] != '\n')
	{
		if (c[i] == ',')
		{
			if (k > 2)
			{
				printf("Invalid color %d %d!\n", j, k);
				return (1);
			}
			j = 0;
			k++;
		}
		else if (ft_isdigit(c[i]) == 0 || j > 3 || k > 2)
		{
			printf("Invalid color %d %d!\n", j, k);
			return (1);
		}
		j++;
	}
	return (0);
}
