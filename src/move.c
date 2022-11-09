/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:58:48 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/09 13:38:09 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_sides(t_data *data, double rad)
{
	if (data->map[(int)(data->posx + (data->dirx * cos(rad) - data->diry
				* sin(rad)) * 0.04)][(int)(data->posy)] != 'X'
					&& data->map[(int)(data->posx + (data->dirx
					* cos(rad) - data->diry * sin(rad))
					* 0.04)][(int)(data->posy)] != '1')
		data->posx += (data->dirx * cos(rad) - data->diry
				* sin(rad)) * 0.04;
	if (data->map[(int)(data->posx)][(int)(data->posy + (data->dirx
				* sin(rad) + data->diry * cos(rad)) * 0.04)] != 'X'
				&& data->map[(int)(data->posx)][(int)(data->posy
				+ (data->dirx * sin(rad) + data->diry * cos(rad))
				* 0.04)] != '1')
		data->posy += (data->dirx * sin(rad) + data->diry
				* cos(rad)) * 0.04;
}

void	move_fb(t_data *data, double numx, double numy)
{
	if (data->map[(int)(data->posx + numx)][(int)(data->posy)] != 'X'
			&& data->map[(int)(data->posx + numx)][(int)(data->posy)] != '1')
		data->posx += numx;
	if (data->map[(int)(data->posx)][(int)(data->posy + numy)] != 'X'
			&& data->map[(int)(data->posx)][(int)(data->posy + numy)] != '1')
		data->posy += numy;
}

void	move_vision(t_data *data, double rad)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(rad) - data->diry * sin(rad);
	data->diry = olddirx * sin(rad) + data->diry * cos(rad);
	oldplanex = data->planex;
	data->planex = data->planex * cos(rad) - data->planey * sin(rad);
	data->planey = oldplanex * sin(rad) + data->planey * cos(rad);
}

void	move(t_data *data)
{
	if (data->vr == 1)
		move_vision(data, -0.04);
	if (data->vl == 1)
		move_vision(data, 0.04);
	if (data->mf == 1)
		move_fb(data, data->dirx * data->speed, data->diry * data->speed);
	if (data->mb == 1)
		move_fb(data, -data->dirx * data->speed, -data->diry * data->speed);
	if (data->ml == 1)
		move_sides(data, 1.5708);
	if (data->mr == 1)
		move_sides(data, 4.71239);
}
