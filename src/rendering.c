/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:48:08 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/09 15:26:23 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_values(t_data *data, int x);
static void	find_hit_point(t_data *data);
static void	print_walls(t_data *data, int x, int y);

/*
	The rendering function contains the while loop that implements the
		raytracing. This loop is called for every 1-pixel width vertical-line.
		In this loop we have 3 steps:
			- init_values()
			- find_hit_point()
			- print_walls()
*/

int	rendering(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_values(data, x);
		find_hit_point(data);
		tex_calc(data);
		print_walls(data, x, 0);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	move(data);
	return (1);
}

/*
	In init_values() we initialize all the values that we need to find the hit
		point in order to calculate data->perpwalldist.
	Perpwalldist is the vector that goes frome the hit_poiny in a wall to the
		closest point in the camera plane.
	To calculate perpwalldist, we need first to know a few things.
	 - Raydirs, they are all the 1920 vectors (WIDTH OF THE CAMERA) that will give
	 	us the information to translate the map in 1 line of pixels per raydir vector.
	 - Deltadist, is the vector that goes from one border of a box-map, to another.
	  	Deltadistx is for the x borders, delatadisty for de y borders.
	 - Sidedist, is the same as deltadist but is only the first one, that goes from
	 	the player to the first border.
*/

static void	init_values(t_data *data, int x)
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
		data->sidedistx = (data->mapx + 1.0 - data->posx) * data->deltadistx;
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->posy - data->mapy) * data->deltadisty;
	}
	else
		data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
}

/*
	Once we have all the values, we can search for the hit point with a wall. To do
		this we have to check for all the borders of box-maps. Checking if sidedistx
		is greater than sidedisty allows us to know what border to search next
		(x or y). Then we check if that border contains a 1 value, if that is
		true we found a wall!
	Now that we found a wall we can calculate perpwalldist.
*/

static void	find_hit_point(t_data *data)
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

/*
	Now that we have perpwalldist, we can calculate when in the vertical line
		of pixels we have tostart printing the wall. And once done that, whe
		first print the ceiling then the wall and last the floor.
*/

static void	print_walls(t_data *data, int x, int y)
{
	data->line = (int)(HEIGHT / data->perpwalldist);
	data->drawstart = (-data->line / 2) + (HEIGHT / 2);
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = (data->line / 2) + (HEIGHT / 2);
	if (data->drawend > HEIGHT)
		data->drawend = HEIGHT;
	y = -1;
	while (++y < data->drawstart)
		my_mlx_pixel_put(data, x, y, data->colorc);
	data->step = 1.0 * data->textures[data->ti].height / data->line;
	data->texpos = (data->drawstart - HEIGHT / 2 + data->line / 2) * data->step;
	y = data->drawstart - 1;
	while (++y < data->drawend)
	{
		data->texy = (int)data->texpos;
		data->texpos += data->step;
		data->color = data->textures[data->ti].addr[data->texy
			* data->textures[data->ti].width + data->texx];
		my_mlx_pixel_put(data, x, y, data->color);
	}
	y--;
	while (++y < HEIGHT)
		my_mlx_pixel_put(data, x, y, data->colorf);
}
