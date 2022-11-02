/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:48:08 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 17:37:28 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key, t_data *data)
{
	if (key == 124)
	{
		data->dir += 8;
		if (data->dir >= 360 || data->dir < 0)
			data->dir = 0;
	}
	else if (key == 123)
	{
		data->dir -= 8;
		if (data->dir >= 360 || data->dir <= -1)
			data->dir = 359;
	}
	return (0);
}

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

void	rendering(t_data *data, int x, int y)
{
	(void) y;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIDTH, HEIGHT, "Cub3D");
	if (!data->win_ptr)
		return ;
	while (++x < 10)
	{
		printf("%f %f %f %f - ", data->dirx, data->diry, data->planex, data->planey);
		data->hit = 0;
		data->camerax = 2 * x / (double)WIDTH - 1;
		data->raydirx = data->dirx + data->planex * data->camerax;
		data->raydiry = data->diry + data->planey * data->camerax;
		data->mapx = (int)data->posx;
		data->mapy = (int)data->posy;
		printf("%f %f %f\n", data->camerax, data->raydirx, data->raydiry);
		data->deltadistx = sqrt(1 + (data->raydiry * data->raydiry)
				/ (data->raydirx * data->raydirx));
		data->deltadisty = sqrt(1 + (data->raydirx * data->raydirx)
				/ (data->raydiry * data->raydiry));
		if (data->dirx < 0)
		{
			data->stepx = -1;
			data->sidedistx = (data->posx - data->mapx) * data->deltadistx;
		}
		else
		{
			data->stepx = 1;
			data->sidedistx = (data->mapx + 1.0 - data->posx)
				* data->deltadistx;
		}
		if (data->diry < 0)
		{
			data->stepy = -1;
			data->sidedisty = (data->posy - data->mapy) * data->deltadisty;
		}
		else
		{
			data->stepy = 0;
			data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
		}
		printf("Hola %f %f %f %f\n", data->sidedistx, data->deltadisty, data->deltadistx, data->deltadisty);
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
			if (data->map[data->mapy][data->mapx] == '1')
			{
				// printf("%c  %d  %d\n", data->map[data->mapy][data->mapx], data->mapy, data->mapx);
				data->hit = 1;
			}
		}
		printf("Adios\n");
		if (data->side == 0)
		{
			data->perpwalldist = (data->mapx - data->posx
					+ (1 + data->stepx) / 2) / data->raydirx;
		}
		else
		{
			data->perpwalldist = (data->mapy - data->posy
					+ (1 + data->stepy) / 2) / data->raydiry;
		}
		data->line = (int)(HEIGHT / data->perpwalldist);
		data->drawstart = -data->line / 2 + HEIGHT / 2;
		if (data->drawstart < 0)
			data->drawstart = 0;
		data->drawend = data->line / 2 + HEIGHT / 2;
		if (data->drawend >= HEIGHT)
			data->drawend = 0;
		// printf("--> %d %d\n", data->drawstart, data->drawend);
	}
	mlx_hook(data->win_ptr, 2, 0, key_handler, &data);
	mlx_loop(data->mlx_ptr);
}
