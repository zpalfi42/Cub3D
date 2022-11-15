/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:17 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/15 13:45:20 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_checker(char *c, int i, int j, int k)
{
	if (ft_strlen(c) > 12 || ft_strlen(c) < 1)
		return (1);
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

int	textures_checker(t_data *data)
{
	int	fd;

	fd = open(data->no, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->so, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->we, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->ea, O_RDONLY, 0);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}
