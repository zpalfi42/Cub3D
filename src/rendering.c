/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:48:08 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/03 13:32:55 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
		y = -1;
		while (++y < 1920)
		{
			if (x < 1080 / 2)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, y, x,
					(get_color(data->c, 0, -1, 0) << 16
						| get_color(data->c, 1, -1, 0) << 8
						| get_color(data->c, 2, -1, 0)));
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, y, x,
					(get_color(data->f, 0, -1, 0) << 16
						| get_color(data->f, 1, -1, 0) << 8
						| get_color(data->f, 2, -1, 0)));
		}
*/

void	init_values(t_data *data, int x)
{
	data->hit = 0;
	data->camerax = (2 * x) / (double)WIDTH - 1;
	data->raydirx = data->dirx + data->planex * data->camerax;
	data->raydiry = data->diry + data->planey * data->camerax;
	data->mapx = (int)data->posx;
	data->mapy = (int)data->posy;
	data->deltadistx = fabs(1 / data->raydirx);
	data->deltadisty = fabs(1 / data->raydiry);
	data->stepx = 1;
	data->stepy = 1;
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->posx - data->mapx) * data->deltadistx;
	}
	else
		data->sidedistx = (data->mapx + 1.0 - data->posx)
			* data->deltadistx;
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->posy - data->mapy) * data->deltadisty;
	}
	else
		data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
}

void	find_hit_point(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (data->map[data->mapx][data->mapy] == '1')
			data->hit = 1;
	}
	if (data->side == 0)
		data->perpwalldist = (data->mapx - data->posx + (1 - data->stepx) / 2)
			/ data->raydirx;
	else
		data->perpwalldist = (data->mapy - data->posy + (1 - data->stepy) / 2)
			/ data->raydiry;
}

void	put_fc(t_data *data, char *c, int i, int x)
{
	int	y;

	y = -1;
	if (i == HEIGHT)
		y = data->drawend - 1;
	while (++y < i)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
			(get_color(c, 0, -1, 0) << 16
				| get_color(c, 1, -1, 0) << 8
				| get_color(c, 2, -1, 0)));
	}
}

void	print_walls(t_data *data, int x, int y)
{
	data->line = (int)(HEIGHT / data->perpwalldist);
	data->drawstart = (-data->line / 2) + (HEIGHT / 2);
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = (data->line / 2) + (HEIGHT / 2);
	if (data->drawend >= HEIGHT)
		data->drawend = 0;
	put_fc(data, data->c, data->drawstart - 1, x);
	y = data->drawstart - 1;
	while (++y < data->drawend)
	{
		if (data->side == 0)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
				(255 << 16
					| 255 << 8
					| 255));
		else
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y,
				(0 << 16
					| 0 << 8
					| 0));
	}
	put_fc(data, data->f, HEIGHT, x);
}

void	rendering(t_data *data, int x, int y)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIDTH, HEIGHT, "Cub3D");
	if (!data->win_ptr)
		return ;
	while (++x < WIDTH)
	{
		init_values(data, x);
		find_hit_point(data);
		print_walls(data, x, y);
	}
	mlx_hook(data->win_ptr, 2, 0, key_handler, &data);
	mlx_loop(data->mlx_ptr);
}
