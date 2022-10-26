/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/26 12:21:18 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data, char *filename)
{
	data->no = NULL;
	data->so = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->f = NULL;
	data->c = NULL;
	data->index = 0;
	data->width = 0;
	data->height = 0;
	data->filename = ft_strdup(filename);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;
	int		first;

	if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4))
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY, 0);
	if (!fd)
	{
		printf("File couldn't be opened!\n");
		return (-1);
	}
	data = malloc(sizeof(t_data *));
	init_data(data, argv[1]);
	first = file_parser(data, fd, 0, 0);
	if (first == 1)
		free_map(data, 0);
	return (0);
}
