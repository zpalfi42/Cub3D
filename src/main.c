/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/08 17:03:41 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief data->colorw1, data->colorw2 can be deleted once we add textures.
 */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
	return (0);
}

void	start(t_data *data)
{
	if (color_checker(data->c, -1, 0, 0) == 0
		&& color_checker(data->f, -1, 0, 0) == 0)
	{
		map_checker(data, 0, 0);
		data->mlx_ptr = mlx_init();
		if (!data->mlx_ptr)
			return ;
		if (get_colors(data) != 0 || get_textures(data) != 0)
			return ;
		data->win_ptr = mlx_new_window(data->mlx_ptr,
				WIDTH, HEIGHT, "Cub3D");
		data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		if (!data->win_ptr)
			return ;
		mlx_hook(data->win_ptr, 2, 0, key_handler, data);
		mlx_hook(data->win_ptr, 3, 0, key_release, data);
		mlx_hook(data->win_ptr, 17, 0, key_exit, data);
		mlx_loop_hook(data->mlx_ptr, rendering, data);
		mlx_loop(data->mlx_ptr);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4))
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (init_data(data, argv[1]))
		return (1);
	data->first = file_parser(data, -1, argv[1]);
	if (data->first == 1)
		start(data);
	else
	{
		printf("There is no map in %s!\n", argv[1]);
		return (1);
	}
	return (0);
}
