/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:17 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/08 16:54:46 by zpalfi           ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_textures
{
	void			*img;
	unsigned int	*addr;

	int				width;
	int				height;

	int				bits_per_pixel;
	int				line_length;
	int				endian;	
}	t_textures;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;

	int			fd;
	int			width;
	int			height;
	int			index;
	int			player;
	int			first;
	int			error;
	int			dir;
	int			colorc;
	int			colorf;
	int			color;

	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		wallx;
	double		step;
	double		texpos;

	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line;
	int			drawstart;
	int			drawend;
	int			texx;
	int			texy;

	int			vr;
	int			vl;
	int			mf;
	int			mb;
	int			ml;
	int			mr;

	char		**map;

	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*f;
	char		*c;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			ti;
	t_textures	textures[4];	
}	t_data;

void	move(t_data *data);
void	malloc_map(t_data *data);
void	free_map(t_data *data, int i);
void	save_map(t_data *data, char *line);
void	save_texture(t_data *data, char *line);
void	map_checker(t_data *data, int i, int j);
void	get_height(t_data *data, char *filename, int i, int j);

char	*del_spaces(char *line, int i);

int		key_exit(t_data *data);
int		rendering(t_data *data);
int		key_release(int key, t_data *data);
int		key_handler(int key, t_data *data);
int		init_data(t_data *data, char *filename);
int		get_color(char *c, int color, int i, int j);
int		color_checker(char *c, int i, int j, int k);
int		file_parser(t_data *data, int i, char *filename);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif