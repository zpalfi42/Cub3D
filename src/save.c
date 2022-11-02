/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:38:58 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 15:27:04 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map(t_data *data, char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	data->map[data->index][0] = 'X';
	while (line[j] != '\0')
	{
		if (line[j] == ' ' || line[j] == '\n')
			data->map[data->index][i] = 'X';
		else
			data->map[data->index][i] = line[j];
		j++;
		i++;
	}
	if (i < data->width + 1)
	{
		while (i < data->width + 1)
		{
			data->map[data->index][i] = 'X';
			i++;
		}
	}
	data->map[data->index][i] = '\0';
	data->index++;
}

void	save_texture(t_data *data, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		data->no = del_spaces(line, 2);
	else if (!ft_strncmp(line, "SO ", 3))
		data->so = del_spaces(line, 2);
	else if (!ft_strncmp(line, "EA ", 3))
		data->ea = del_spaces(line, 2);
	else if (!ft_strncmp(line, "WE ", 3))
		data->we = del_spaces(line, 2);
	else if (!ft_strncmp(line, "F ", 2))
		data->f = del_spaces(line, 1);
	else if (!ft_strncmp(line, "C ", 2))
		data->c = del_spaces(line, 1);
}
