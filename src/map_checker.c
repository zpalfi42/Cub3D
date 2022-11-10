/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:03:19 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/10 17:36:33 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_point(t_data *data, int i, int j)
{
	if (data->map[i][j] != 'X'
		&& data->map[i][j] != '1'
		&& data->map[i][j] != '\0')
		return (0);
	return (1);
}

static void	player_point(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->dirx = -1;
		data->planey = 0.66;
	}
	else if (data->map[i][j] == 'S')
	{
		data->dirx = 1;
		data->planey = -0.66;
	}
	else if (data->map[i][j] == 'E')
	{
		data->diry = 1;
		data->planex = 0.66;
	}
	else if (data->map[i][j] == 'W')
	{
		data->diry = -1;
		data->planex = -0.66;
	}
	else
		return ;
	data->posx = i + 0.5;
	data->posy = j + 0.5;
	data->player++;
}

static void	x_point(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'X')
	{
		if (!valid_point(data, i, j + 1)
			|| (data->map[i + 1] != NULL && !valid_point(data, i + 1, j))
			|| (i > 0 && data->map[i - 1] != NULL
				&& !valid_point(data, i - 1, j))
			|| (j > 0 && !valid_point(data, i, j - 1)))
		{
			printf("Map error\n");
			data->error = 1;
		}
	}
}

static	void	other_point(t_data *data, int i, int j)
{
	if (data->map[i][j] != 'X' && data->map[i][j] != '1'
		&& data->map[i][j] != '0' && data->map[i][j] != 'N'
			&& data->map[i][j] != 'W' && data->map[i][j] != 'S'
			&& data->map[i][j] != 'E')
	{
		printf("Not a valid character!\n");
		data->error = 1;
	}
}

int	map_checker(t_data *data, int i, int j)
{
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			x_point(data, i, j);
			player_point(data, i, j);
			other_point(data, i, j);
			j++;
		}
		i++;
	}
	if (data->player != 1)
	{
		printf("There are %d players in the map, it should be only one!\n",
			data->player);
		data->error = 1;
	}
	return (data->error);
}
