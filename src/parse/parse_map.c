/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by matilde           #+#    #+#             */
/*   Updated: 2024/03/26 17:51:27 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parsing(char *path)
{
	int	i;
	int	fd;

	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'c') && (path[i - 2] == 'u'
			&& path[i - 1] == 'b'))
	{
		fd = open(path, O_RDONLY);
		map_global()->path = malloc(ft_strlen(path) + 1);
		if (map_global()->path == NULL)
			error("Fail to allocate memory");
		ft_strlcpy(map_global()->path, path, ft_strlen(path) + 1);
		check_map(path);
		check_chars(-1);
		check_wall();
		map_global()->gnl = NULL;
		prep_texture(path);
	}
	else
		error("Invalid map");
}

void	check_map(char *path)
{
	int	i;

	(map_global()->fd) = open(path, O_RDONLY);
	if (map_global()->fd < 0)
		error("Failed to open file");
	(map_global()->gnl) = (get_next_line(map_global()->fd, 0, 0, NULL));
	if (!map_global()->gnl)
		error("Invalid map");
	while (map_global()->gnl)
	{
		i = 0;
		while (map_global()->gnl[i] && map_global()->gnl[i] == ' ')
			i++;
		if (map_global()->gnl[i] != '1')
		{
			free(map_global()->gnl);
			(map_global()->gnl) = (get_next_line(map_global()->fd, 0, 0, NULL));
			if (!map_global()->gnl)
				error("Invalid map");
		}
		else
			break ;
	}
	if (map_global()->gnl && map_global()->gnl[i] == '1')
		init_map();
}

void	init_map(void)
{
	t_map	*map1;
	int		max;
	char	*line;
	int		i;

	map1 = map();
	max = 0;
	i = 0;
	while (map_global()->gnl != NULL)
	{
		line = rm_nl(map_global()->gnl);
		ft_memcpy(map_global()->gnl, line, ft_strlen(line) + 1);
		map1->line = malloc(ft_strlen(map_global()->gnl) + 1);
		if (map1->line == NULL)
			error("Fail to allocate memory");
		ft_memcpy(map1->line, map_global()->gnl, ft_strlen(map_global()->gnl)
			+ 1);
		map1->i = i++;
		max = aux_map(map1, max);
		map1 = map1->next;
	}
	free(map_global()->gnl);
	close(map_global()->fd);
	map_global()->x_max = max;
	map_global()->y_max = i;
}

int	aux_map(t_map *map1, int max)
{
	map1->len = ft_strlen(map1->line);
	if (map1->len > max)
		max = map1->len;
	free(map_global()->gnl);
	(map_global()->gnl) = (get_next_line(map_global()->fd, 0, 0, NULL));
	if (map_global()->gnl != NULL)
	{
		map1->next = malloc(sizeof(t_map));
		if (map1->next == NULL)
			error("Fail to allocate memory");
		map1->next->prev = map1;
	}
	else
		map1->next = NULL;
	return (max);
}

void	check_chars(int i)
{
	int		pos;
	t_map	*mp;

	pos = 0;
	mp = map();
	while (mp)
	{
		i = -1;
		while (++i < mp->len)
		{
			if (mp->line[i] == 'N' || mp->line[i] == 'S' || mp->line[i] == 'E'
				|| mp->line[i] == 'W')
			{
				pos += 1;
				if (pos != 1)
					error("Invalid contents in map");
				map_global()->pos_x = i;
				map_global()->pos_y = mp->i;
			}
			else if (mp->line[i] != 48 && mp->line[i] != 49
				&& mp->line[i] != 32)
				error("Invalid contents in map");
		}
		mp = mp->next;
	}
}
