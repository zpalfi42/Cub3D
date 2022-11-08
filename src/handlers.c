/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:27:34 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/08 16:32:25 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(t_data *data)
{
	free_map(data, 0);
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
	return (0);
}
