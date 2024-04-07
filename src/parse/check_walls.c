/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:06 by matilde           #+#    #+#             */
/*   Updated: 2024/04/07 23:16:12 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
