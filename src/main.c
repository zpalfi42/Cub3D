/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/15 16:19:09 by zpalfi           ###   ########.fr       */
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

int	start(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	if (get_colors(data) == 0 && get_textures(data) == 0)
	{
		data->win_ptr = mlx_new_window(data->mlx_ptr,
				WIDTH, HEIGHT, "Cub3D");
		data->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		if (!data->win_ptr)
			return (1);
		mlx_hook(data->win_ptr, 2, 0, key_handler, data);
		mlx_hook(data->win_ptr, 3, 0, key_release, data);
		mlx_hook(data->win_ptr, 17, 0, key_exit, data);
		mlx_loop_hook(data->mlx_ptr, rendering, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		return (1);
	return (0);
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
	{
		free(data);
		return (1);
	}
	data->first = file_parser(data, -1, argv[1]);
	if (textures_checker(data) != 0 || color_checker(data->c, -1, 0, 0) != 0
		|| color_checker(data->f, -1, 0, 0) != 0)
		printf("Invalid textures or colors!\n");
	else if (data->first == 1 && map_checker(data, 0, 0) != 1)
		return (start(data));
	else if (data->error != 1)
		printf("There is no map in %s!\n", argv[1]);
	free_data(data, 0);
	return (1);
}
