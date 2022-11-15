/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:39:01 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/15 16:07:44 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_img_addr(t_data *data)
{
	data->textures[0].addr = (unsigned int *)mlx_get_data_addr
		(data->textures[0].img, &data->textures[0].bits_per_pixel,
			&data->textures[0].line_length, &data->textures[0].endian);
	data->textures[1].addr = (unsigned int *)mlx_get_data_addr
		(data->textures[1].img, &data->textures[1].bits_per_pixel,
			&data->textures[1].line_length, &data->textures[1].endian);
	data->textures[2].addr = (unsigned int *)mlx_get_data_addr
		(data->textures[2].img, &data->textures[2].bits_per_pixel,
			&data->textures[2].line_length, &data->textures[2].endian);
	data->textures[3].addr = (unsigned int *)mlx_get_data_addr
		(data->textures[3].img, &data->textures[3].bits_per_pixel,
			&data->textures[3].line_length, &data->textures[3].endian);
}

int	get_textures(t_data *data)
{
	data->textures[0].img = mlx_xpm_file_to_image(data->mlx_ptr, data->no,
			&data->textures[0].width, &data->textures[0].height);
	data->textures[1].img = mlx_xpm_file_to_image(data->mlx_ptr, data->so,
			&data->textures[1].width, &data->textures[1].height);
	data->textures[2].img = mlx_xpm_file_to_image(data->mlx_ptr, data->ea,
			&data->textures[2].width, &data->textures[2].height);
	data->textures[3].img = mlx_xpm_file_to_image(data->mlx_ptr, data->we,
			&data->textures[3].width, &data->textures[3].height);
	if (!data->textures[0].img || !data->textures[1].img
		|| !data->textures[2].img || !data->textures[3].img)
	{
		printf("Invalid texture!\n");
		free_all(data, 0);
		return (1);
	}
	get_img_addr(data);
	return (0);
}

static int	get_color(char *c, int color, int i, int j)
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

int	get_colors(t_data *data)
{
	data->colorc = (get_color(data->c, 0, -1, 0) << 16
			| get_color(data->c, 1, -1, 0) << 8
			| get_color(data->c, 2, -1, 0));
	data->colorf = (get_color(data->f, 0, -1, 0) << 16
			| get_color(data->f, 1, -1, 0) << 8
			| get_color(data->f, 2, -1, 0));
	return (0);
}
