/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:07:05 by matilde           #+#    #+#             */
/*   Updated: 2024/03/15 14:08:33 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_angle(void)
{
	t_map	*map1;
	int		i;
	int		player_angle;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N')
				player_angle = 0;
			else if (map1->line[i] == 'S')
				player_angle = 180;
			else if (map1->line[i] == 'E')
				player_angle = 90;
			else if (map1->line[i] == 'W')
				player_angle = 270;
		}
		map1 = map1->next;
	}
	return (player_angle);
}

int	calculate_texture_index(void)
{
	int	pos;
	int	player;

	pos = -1;
	player = player_angle();
	if (player == 0)
	{
		pos = 'N';
		if (ray()->intersect_x < map_global()->pos_x)
			pos = 'W';
		else if (ray()->intersect_x > map_global()->pos_x)
			pos = 'E';
	}
	else if (player == 180)
	{
		pos = 'S';
		if (ray()->intersect_x < map_global()->pos_x)
			pos = 'E';
		else if (ray()->intersect_x > map_global()->pos_x)
			pos = 'W';
	}
	else
		texture_index(player, &pos);
	return (pos);
}

void	texture_index(int player, int *pos)
{
	if (player == 90)
	{
		*pos = 'E';
		if (ray()->intersect_y > map_global()->pos_y)
			*pos = 'N';
		else if (ray()->intersect_y < map_global()->pos_y)
			*pos = 'S';
	}
	else if (player == 270)
	{
		*pos = 'W';
		if (ray()->intersect_y > map_global()->pos_y)
			*pos = 'N';
		else if (ray()->intersect_y < map_global()->pos_y)
			*pos = 'S';
	}
}
