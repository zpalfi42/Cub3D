/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 14:20:26 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data, char *filename)
{
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->f = NULL;
	data->c = NULL;
	data->ww = 1920;
	data->wh = 1080;
	data->player = 0;
	data->index = 0;
	data->width = 0;
	data->height = 0;
	data->first = 0;
	data->error = 0;
	data->dir = 0;
	data->filename = ft_strdup(filename);
	data->fd = open(filename, O_RDONLY, 0);
	if (data->fd < 0)
	{
		printf("File couldn't be opened!\n");
		return (0);
	}
	return (0);
}

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
	printf("%d\n", data->dir);
	return (0);
}

int	get_color(char *c, int color, int i, int j)
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
	while (c[++i] != '\0')
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

void	rendering(t_data *data, int x, int y)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->ww, data->wh, "Cub3D");
	if (!data->win_ptr)
		return ;
	while (++x < 1080)
	{
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
	}
	mlx_hook(data->win_ptr, 2, 0, key_handler, &data);
	mlx_loop(data->mlx_ptr);
}

int	textures_checker(char *c, int i, int j, int k)
{
	if (ft_strlen(c) > 12)
	{
		printf("Invalid color!\n");
		return (1);
	}
	while (c[++i] != '\0' && c[i] != '\n')
	{
		if (c[i] == ',')
		{
			if (k > 2)
			{
				printf("Invalid color %d %d!\n", j, k);
				return (1);
			}
			j = 0;
			k++;
		}
		else if (ft_isdigit(c[i]) == 0 || j > 3 || k > 2)
		{
			printf("Invalid color %d %d!\n", j, k);
			return (1);
		}
		j++;
	}
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
		return (1);
	data->first = file_parser(data, 0, argv[1]);
	if (data->first == 1)
	{
		if (textures_checker(data->c, -1, 0, 0) == 0
			&& textures_checker(data->f, -1, 0, 0) == 0)
		{
			map_checker(data, 0, 0);
			rendering(data, -1, 0);
		}
	}
	else
	{
		printf("There is no map in %s!\n", argv[1]);
		return (1);
	}
	free_map(data, 0);
	return (0);
}
