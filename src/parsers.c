/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:20:09 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/08 17:03:31 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_textures(t_data *data)
{
	if (data->no && data->so && data->ea && data->we && data->c && data->f)
		return (0);
	return (1);
}

int	map_parser(t_data *data, char *line, int i, char *filename)
{
	if (data->first == 0)
	{
		close(data->fd);
		get_height(data, filename, i, 0);
		data->map = malloc (sizeof(char *) * (data->height + 3));
		malloc_map(data);
		data->first = 1;
		save_map(data, "\0");
		save_map(data, line);
		data->fd = open(filename, O_RDONLY, 0);
		while (i >= 0)
		{
			free(line);
			line = get_next_line(data->fd);
			i--;
		}
	}
	else
	{
		if (data->index < (data->height + 1))
			save_map(data, line);
		else
			save_map(data, "\0");
	}
	return (data->first);
}

int	file_parser(t_data *data, int i, char *filename)
{
	char	*line;
	char	*aux;

	while (42 && ++i)
	{
		line = get_next_line(data->fd);
		if (!line)
		{
			if (data->first == 1)
				save_map(data, "\0");
			break ;
		}
		aux = del_spaces(line, 0);
		if (aux != NULL)
		{
			if (all_textures(data))
				save_texture(data, del_spaces(line, 0));
			else
				data->first = map_parser(data, line, i, filename);
		}
		free(line);
		free(aux);
	}
	close(data->fd);
	return (data->first);
}
