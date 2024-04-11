/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by matilde           #+#    #+#             */
/*   Updated: 2024/04/11 11:56:37 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	parsing(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'c') && (path[i - 2] == 'u'
			&& path[i - 1] == 'b'))
	{
		map_global()->path = malloc(ft_strlen(path) + 1);
		if (map_global()->path == NULL)
			error("Fail to allocate memory");
		ft_strlcpy(map_global()->path, path, ft_strlen(path) + 1);
		check_map(path);
		check_chars(-1, 0);
		check_wall(0);
		check_walls();
		map_global()->gnl = NULL;
		open_textures(path);
		prep_texture(0, 0, NULL, NULL);
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
		init_map(0, 0, NULL, map());
}

void	init_map(int i, int max, char *line, t_map *map1)
{
	while (map_global()->gnl != NULL)
	{
		line = rm_space(rm_nl(map_global()->gnl));
		if (!line)
		{
			map1->prev->next = NULL;
			free(map1);
			error("Invalid map");
		}
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

void	start_pos_dir(char c)
{
	if (c == 'N')
	{
		cub3()->ray.dir = (t_point){0, 1};
		cub3()->ray.pos = (t_point){0.66, 0};
	}
	else if (c == 'S')
	{
		cub3()->ray.dir = (t_point){0, 1};
		cub3()->ray.pos = (t_point){-0.66, 0};
	}
	else if (c == 'E')
	{
		cub3()->ray.dir = (t_point){1, 0};
		cub3()->ray.pos = (t_point){0, 0.66};
	}
	else if (c == 'W')
	{
		cub3()->ray.dir = (t_point){-1, 0};
		cub3()->ray.pos = (t_point){0, -0.66};
	}
	else
		return ;
}
