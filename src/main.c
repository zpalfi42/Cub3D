/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/03 17:18:28 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_colors(t_data *data)
{
	data->colorc = (get_color(data->c, 0, -1, 0) << 16
			| get_color(data->c, 1, -1, 0) << 8
			| get_color(data->c, 2, -1, 0));
	data->colorf = (get_color(data->f, 0, -1, 0) << 16
			| get_color(data->f, 1, -1, 0) << 8
			| get_color(data->f, 2, -1, 0));
	data->colorw1 = (255 << 16
			| 255 << 8
			| 255);
	data->colorw2 = (0 << 16
			| 0 << 8
			| 0);
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
		data->win_ptr = mlx_new_window(data->mlx_ptr,
				WIDTH, HEIGHT, "Cub3D");
		data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		get_colors(data);
		if (!data->win_ptr)
			return ;
		mlx_hook(data->win_ptr, 2, 0, key_handler, data);
		mlx_hook(data->win_ptr, 3, 0, key_release, data);
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
	data->first = file_parser(data, 0, argv[1]);
	if (data->first == 1)
		start(data);
	else
	{
		printf("There is no map in %s!\n", argv[1]);
		return (1);
	}
	free_map(data, 0);
	return (0);
}
