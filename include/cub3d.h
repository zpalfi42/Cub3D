/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:17 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/26 12:21:35 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		width;
	int		height;
	int		index;

	char	**map;

	char	*filename;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*f;
	char	*c;
}	t_data;

void	malloc_map(t_data *data);
void	free_map(t_data *data, int i);
void	save_map(t_data *data, char *line);
void	save_texture(t_data *data, char *line);
void	get_height(t_data *data, char *filename, int i, int j);

char	*del_spaces(char *line, int i);

int		file_parser(t_data *data, int fd, int i, int first);

#endif