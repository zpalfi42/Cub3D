/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:32:59 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/15 14:07:52 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data *data, int i)
{
	if (data->map)
	{
		while (data->map[i] != NULL && i < data->height + 2)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->nos == 1)
		free(data->no);
	if (data->sos == 1)
		free(data->so);
	if (data->wes == 1)
		free(data->we);
	if (data->eas == 1)
		free(data->ea);
	if (data->fs == 1)
		free(data->f);
	if (data->cs == 1)
		free(data->c);
	free(data);
}

void	free_all(t_data *data, int i)
{
	if (data->nos == 1)
		mlx_destroy_image(data->mlx_ptr, data->textures[0].img);
	if (data->sos == 1)
		mlx_destroy_image(data->mlx_ptr, data->textures[1].img);
	if (data->eas == 1)
		mlx_destroy_image(data->mlx_ptr, data->textures[2].img);
	if (data->wes == 1)
		mlx_destroy_image(data->mlx_ptr, data->textures[3].img);
	if (data->img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->win_ptr != NULL)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_data(data, i);
}
