/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:50:20 by zpalfi            #+#    #+#             */
/*   Updated: 2022/10/24 17:57:48 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// char    *getTexture(char *line, int i)
// {
//     char    *newline;
//     int     j;

//     newline = malloc(sizeof(char) * (ft_strlen(line) - 2));
// }

char    *delSpaces(char *line, int i)
{
    int j;
    int z;
    char    *newline;

    z = i;
    while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t' 
            || line[i] == '\v' || line[i] == '\f' || line[i] == '\r'))
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

int saveTexture(t_data *data, char *line)
{
    if (!ft_strncmp(line, "NO ", 3))
        data->no = delSpaces(line, 2);
    else if (!ft_strncmp(line, "SO ", 3))
        data->so = delSpaces(line, 2);
    else if (!ft_strncmp(line, "EA ", 3))
        data->ea = delSpaces(line, 2);
    else if (!ft_strncmp(line, "WE ", 3))
        data->we = delSpaces(line, 2);
    else if (!ft_strncmp(line, "F ", 2))
        data->f = delSpaces(line, 1);
    else if (!ft_strncmp(line, "C ", 2))
        data->c = delSpaces(line, 1);
    return (0);
}

int allTextures(t_data *data)
{
    if (data->no && data->so && data->ea && data->we && data->c && data->f)
        return (0);
    return (1);
}

void    getHeight(t_data *data, char *filename, int i)
{
    int     fd;
    int     j;
    char    *line;

    fd = open(filename, O_RDONLY, 0);
    if (!fd)
    {
        printf("File couldn't be opened!\n");
        return ;
    }
    j = 0;
    data->width = 0;
    data->height = 0;
    while (42)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (j < i)
        {
            j++;
            continue;
        }
        if ((int)ft_strlen(line) > data->width)
            data->width = ft_strlen(line);
        data->height++;
    }
}

void mallocMap(t_data *data)
{
    int i;

    i = 0;
    while (i < data->height)
    {
        data->map[i] = malloc(sizeof(char) * data->width);
        i++;
    }
    data->map[i] = NULL;
}

void    saveMap(t_data *data, char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == ' ' || line[i] == '\n')
            data->map[data->index][i] = 'X';
        else
            data->map[data->index][i] = line[i];
        i++;
    }
    if (i < data->width)
    {
        while (i < data->width)
        {
            data->map[data->index][i] = 'X';
            i++;
        }
    }
    data->map[data->index][i] = '\0';
    data->index++;
}

int main(int argc, char **argv)
{
    t_data  *data;
    int     fd;
    char    *line;
    int     i;
    int     first;

    if (argc != 2 || ft_strrncmp(argv[1], ".cub", 4))
    {
        printf("Invalid number of arguments\n");
        return (1);
    }
    fd = open(argv[1], O_RDONLY, 0);
    if (!fd)
    {
        printf("File couldn't be opened!\n");
        return (-1);
    }
    data = malloc(sizeof(t_data *));
    data->no = NULL;
    data->so = NULL;
    data->ea = NULL;
    data->we = NULL;
    data->f = NULL;
    data->c = NULL;
    data->index = 0;
    i = 0;
    first = 0;
    while (42)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (delSpaces(line, 0) == NULL)
        {
            i++;
            continue;
        }
        if (allTextures(data))
            saveTexture(data, delSpaces(line, 0));
        else
        {
            if (first == 0)
            {
                getHeight(data, argv[1], i);
                data->map = malloc (sizeof(char *) * data->height);
                mallocMap(data);
                first = 1;
                saveMap(data, line);
            }
            else
                saveMap(data, line);
        }
        i++;
    }
    first = 0;
    while (data->map[first] != NULL && first < data->height)
    {
        printf("%s\n", data->map[first]);
        free(data->map[first]);
        first++;
    }
    free(data->map);
    // mlx_ptr = mlx_init();
    // if (!mlx_ptr)
    //     return (1);
    // win_ptr = mlx_new_window(mlx_ptr, 1280, 1024, "Cub3D");
    // mlx_loop(mlx_ptr);
    return (0);
}