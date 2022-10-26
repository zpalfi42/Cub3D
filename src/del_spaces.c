/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:08:50 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/26 12:09:38 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*del_spaces(char *line, int i)
{
	int		j;
	int		z;
	char	*newline;

	z = i;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\n'
			|| line[i] == '\t' || line[i] == '\v'
			|| line[i] == '\f' || line[i] == '\r'))
		i++;
	j = 0;
	while (line[j] != '\0')
		j++;
	if ((j - i) == 0)
		return (NULL);
	newline = malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (line[i] != '\0')
	{
		newline[j] = line[i];
		i++;
		j++;
	}
	newline[j] = '\0';
	return (newline);
}
