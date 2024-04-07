/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:06 by matilde           #+#    #+#             */
/*   Updated: 2024/04/07 15:59:59 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
				{
					if (map1->i == 0 && map1->next->line[i] && map1->next->line[i] != '1')
					{
						printf("%s\n", map1->next->line);
						printf("%i, %i, %c\n", map1->i, i, map1->next->line[i]);
						error("Invalid walls of map1");
					}
					else if (map1->i == map_global()->y_max - 1 \
						&& map1->prev->line[i] != '1')
						error("Invalid walls of map2");
				}
				i++;
			}
		}
		map1 = check_wallhelp(map1);
	}
}

t_map	*check_wallhelp(t_map *map1)
{
	if ((map1->line[0] != '1' && map1->line[0] != ' ') \
		|| map1->line[map1->len - 1] != '1')
		error("Invalid walls of map3");
	map1 = map1->next;
	return (map1);
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
				if (map1->line[map1->len -1 - conta] != '1')
					error("Invalid walls of map4");
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
			if (map1->prev->line[map1->prev->len -1 - conta] != '1')
				error("Invalid walls of map5");
		}
	}
}
