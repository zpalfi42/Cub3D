/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:32:59 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/10 17:17:37 by zpalfi           ###   ########.fr       */
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
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
	free(data);
}

void	free_all(t_data *data, int i)
{
	mlx_destroy_image(data->mlx_ptr, data->textures[0].img);
	mlx_destroy_image(data->mlx_ptr, data->textures[1].img);
	mlx_destroy_image(data->mlx_ptr, data->textures[2].img);
	mlx_destroy_image(data->mlx_ptr, data->textures[3].img);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_data(data, i);
}
