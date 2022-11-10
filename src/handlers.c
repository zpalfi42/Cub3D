/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:27:34 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/10 13:53:42 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(t_data *data)
{
	free_all(data, 0);
	exit(0);
}

int	key_handler(int key, t_data *data)
{
	if (key == 124)
		data->vr = 1;
	else if (key == 123)
		data->vl = 1;
	else if (key == 13)
		data->mf = 1;
	else if (key == 0)
		data->ml = 1;
	else if (key == 1)
		data->mb = 1;
	else if (key == 2)
		data->mr = 1;
	else if (key == 53)
		key_exit(data);
	else if (key == 257)
		data->speed = 0.12;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 124)
		data->vr = 0;
	else if (key == 123)
		data->vl = 0;
	else if (key == 13)
		data->mf = 0;
	else if (key == 0)
		data->ml = 0;
	else if (key == 1)
		data->mb = 0;
	else if (key == 2)
		data->mr = 0;
	else if (key == 257)
		data->speed = 0.06;
	return (0);
}
