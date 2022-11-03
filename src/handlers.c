/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:27:34 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/03 13:32:49 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_handler(int key, t_data *data)
{
	if (key == 124)
	{
		data->dir += 8;
		if (data->dir >= 360 || data->dir < 0)
			data->dir = 0;
	}
	else if (key == 123)
	{
		data->dir -= 8;
		if (data->dir >= 360 || data->dir <= -1)
			data->dir = 359;
	}
	return (0);
}
