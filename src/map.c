/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by matilde           #+#    #+#             */
/*   Updated: 2024/02/15 17:12:59 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_name(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'c')
		&& (path[i - 2] == 'u' && path[i - 1] == 'b'))
		check_map(path);
	else
		error("Invalid map");
}

void	check_map(char *path)
{
	int		fd;
	char	*gnl;
	int		i;

	fd = open(path, O_RDONLY);
	gnl = get_next_line(fd);
	if (!gnl)
		error("Invalid map");
	while (gnl)
	{
		i = 0;
		while (gnl[i] == ' ')
			i++;
		if (gnl[i] != '1')
		{
			free(gnl);
			gnl = get_next_line(fd);
		}
		else
			break ;
	}
	check_size(gnl, fd, path);
}

//doesnt have to be rectangle, but walls still need to be 1 
void	check_size(char *gnl, int fd, char *path)
{
	int	size_y;
	int	len;

	size_y = 0;
	len = ft_strlen(gnl) - 1;
	while (gnl != NULL)
	{
		free(gnl);
		gnl = get_next_line(fd);
		size_y++;
	}
	free(gnl);
	close(fd);
	if (len < 3 || size_y < 3)
		error("Invalid map");
	init_matrix(path, len, size_y);
}

// put in matrix n malloc
void	init_matrix(char *path, int len, int size_y)
{
	int		fd;
	int		count;
	char	*line;

	map()->matrix = malloc(sizeof(char *) * (size_y + 1));
	map()->size_y = size_y;
	map()->size_x = len;
	count = -1;
	fd = open(path, O_RDONLY);
	while (++count < map()->size_y)
	{
		map()->matrix[count] = malloc(sizeof(char) * (map()->size_x + 1));
		line = get_next_line(fd);
		ft_strcpy(map()->matrix[count], rm_nl(line));
		free(line);
	}
	close(fd);
	check_wall();
}

void	check_wall(void)
{
	int		count;

	count = -1;
	while (++count < map()->size_x)
	{
		if ((map()->matrix[0][count] != '1'
			|| map()->matrix[map()->size_y -1][count] != '1') \
			&& ((map()->matrix[0][count] != ' ') \
			|| (map()->matrix[map()->size_y -1][count] != ' ')))
			error("Invalid walls of map");
	}
	count = 0;
	while (++count < map()->size_y)
	{
		if ((map()->matrix[count][0] != '1'
			|| map()->matrix[count][map()->size_x -1] != '1') \
			&& ((map()->matrix[count][0] != ' ') \
			|| (map()->matrix[count][map()->size_x -1] != ' ')))
			error("Invalid walls of map");
	}
	check_chars();
}
