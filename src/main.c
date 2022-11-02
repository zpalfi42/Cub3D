/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 16:50:25 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start(t_data *data)
{
	if (color_checker(data->c, -1, 0, 0) == 0
		&& color_checker(data->f, -1, 0, 0) == 0)
	{
		map_checker(data, 0, 0);
		rendering(data, -1, 0);
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
