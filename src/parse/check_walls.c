/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:06 by matilde           #+#    #+#             */
/*   Updated: 2024/04/10 17:30:42 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_chars(int i, int pos)
{
	t_map	*mp;

	mp = map();
	while (mp)
	{
		i = -1;
		while (++i < mp->len)
		{
			if (mp->line[i] == 'N' || mp->line[i] == 'S' || mp->line[i] == 'E'
				|| mp->line[i] == 'W')
			{
				start_pos_dir(mp->line[i]);
				pos += 1;
				map_global()->px = i;
				map_global()->py = mp->i;
				map_global()->orientation = mp->line[i];
			}
			else if (mp->line[i] != 48 && mp->line[i] != 49
				&& mp->line[i] != 32)
				error("Invalid contents in map");
		}
		mp = mp->next;
	}
	if (pos != 1)
		error("Invalid contents in map");
}

void	check_wall(int i)
{
	t_map	*map1;

	map1 = map();
	while (map1)
	{
		i = 0;
		if (map1->i == 0 || map1->i == map_global()->y_max - 1)
		{
			while (map1->line[i] == ' ')
				i++;
			while (i < map1->len)
			{
				if (map1->line[i] == ' ')
					wall(i, map1);
				if (map1->line[i] == '0')
					error("Invalid walls of map");
				i++;
			}
		}
		if ((map1->line[0] != '1' && map1->line[0] != ' ')
			|| map1->line[map1->len - 1] != '1')
			error("Invalid walls of map");
		map1 = map1->next;
	}
}

void	wall(int i, t_map *map1)
{
	if (map1->i == 0 && map1->next->line[i] != '1')
		error("Invalid walls of map");
	else if (map1->i == map_global()->y_max - 1 && map1->prev->line[i] != '1')
		error("Invalid walls of map");
}

void	check_walls(void)
{
	t_map	*map1;
	int		conta;

	map1 = map();
	while (map1)
	{
		if (map1->i != 0 && map1->prev->len < map1->len)
		{
			conta = map1->len - map1->prev->len;
			while (--conta >= 0)
			{
				if (map1->line[map1->len - 1 - conta] != '1')
					error("Invalid walls of map");
			}
		}
		check_walls2(map1);
		map1 = map1->next;
	}
}

void	check_walls2(t_map *map1)
{
	int	conta;

	if (map1->i != 0 && map1->prev->len > map1->len)
	{
		conta = map1->prev->len - map1->len;
		while (--conta >= 0)
		{
			if (map1->prev->line[map1->prev->len - 1 - conta] != '1')
				error("Invalid walls of map");
		}
	}
}
