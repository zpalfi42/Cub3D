/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:15:57 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/09 12:16:59 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_i(t_data *data)
{
	if (data->side == 0 && data->stepx == -1)
		return (0);
	if (data->side == 0 && data->stepx == 1)
		return (1);
	if (data->side == 1 && data->stepy == 1)
		return (2);
	if (data->side == 1 && data->stepy == -1)
		return (3);
	return (0);
}

void	tex_calc(t_data *data)
{
	data->ti = get_texture_i(data);
	if (data->side == 0)
		data->wallx = data->posy + data->perpwalldist * data->raydiry;
	else
		data->wallx = data->posx + data->perpwalldist * data->raydirx;
	data->wallx -= floor(data->wallx);
	data->texx = (int)(data->wallx * data->textures[data->ti].width);
	if (data->side == 0 && data->raydirx > 0)
		data->texx = data->textures[data->ti].width - data->texx - 1;
	if (data->side == 1 && data->raydiry < 0)
		data->texx = data->textures[data->ti].width - data->texx - 1;
}
