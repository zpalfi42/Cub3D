/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:46:47 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 18:20:57 by zpalfi           ###   ########.fr       */
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
	data->player = 0;
	data->index = 0;
	data->width = 0;
	data->height = 0;
	data->first = 0;
	data->error = 0;
	data->dir = 0;
	data->dirx = 0;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->filename = ft_strdup(filename);
	data->fd = open(filename, O_RDONLY, 0);
	if (data->fd < 0)
	{
		printf("File couldn't be opened!\n");
		return (0);
	}
	return (0);
}
