/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:20:09 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/26 12:21:36 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_textures(t_data *data)
{
	if (data->no && data->so && data->ea && data->we && data->c && data->f)
		return (0);
	return (1);
}

static int	map_parser(t_data *data, char *line, int first, int i)
{
	if (first == 0)
	{
		get_height(data, data->filename, i, 0);
		data->map = malloc (sizeof(char *) * (data->height + 3));
		malloc_map(data);
		first = 1;
		save_map(data, "\0");
		save_map(data, line);
	}
	else
	{
		if (data->index < (data->height + 1))
			save_map(data, line);
		else
			save_map(data, "\0");
	}
	return (first);
}

int	file_parser(t_data *data, int fd, int i, int first)
{
	char	*line;

	while (42)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (first == 1)
				save_map(data, "\0");
			break ;
		}
		if (del_spaces(line, 0) == NULL)
		{
			i++;
			continue ;
		}
		if (all_textures(data))
			save_texture(data, del_spaces(line, 0));
		else
			first = map_parser(data, line, first, i);
		i++;
	}
	return (first);
}
