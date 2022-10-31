/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/31 12:06:02 by zpalfi           ###   ########.fr       */
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
	data->ww = 1280;
	data->wh = 1024;
	data->player = 0;
	data->index = 0;
	data->width = 0;
	data->height = 0;
	data->first = 0;
	data->error = 0;
	data->filename = ft_strdup(filename);
	data->fd = open(data->filename, O_RDONLY, 0);
	if (!data->fd)
	{
		printf("File couldn't be opened!\n");
		return (1);
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
	data = malloc(sizeof(t_data *));
	if (init_data(data, argv[1]))
		return (1);
	data->first = file_parser(data, data->fd, 0, argv[1]);
	if (data->first == 1)
	{
		map_checker(data, 0, 0);
		free_map(data, 0);
	}
	else
	{
		printf("There is no map in %s!\n", argv[1]);
		return (1);
	}
	return (0);
}
