/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:32:59 by zpalfi            #+#    #+#             */
/*   Updated: 2022/11/02 15:27:07 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_data *data, int i)
{
	while (data->map[i] != NULL && i < data->height + 2)
	{
		printf("%s\n", data->map[i]);
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
