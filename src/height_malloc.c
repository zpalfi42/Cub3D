/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:07:15 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/08 14:14:43 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_height(t_data *data, char *filename, int i, int j)
{
	char	*line;

	data->fd = open(filename, O_RDONLY, 0);
	if (data->fd < 0)
	{
		printf("File couldn't be opened!\n");
		return ;
	}
	while (42)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		if (j < i)
			j++;
		else
		{
			if ((int)ft_strlen(line) > data->width)
				data->width = ft_strlen(line);
			data->height++;
		}
		free(line);
	}
	close(data->fd);
}

void	malloc_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height + 2)
	{
		data->map[i] = malloc(sizeof(char) * (data->width + 3));
		i++;
	}
	data->map[i] = NULL;
}
