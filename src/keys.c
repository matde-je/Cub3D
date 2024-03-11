/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:55 by matilde           #+#    #+#             */
/*   Updated: 2024/03/08 16:19:19 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(int i)
{
	t_map	*map1;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N' || map1->line[i] == 'S' \
				|| map1->line[i] == 'E' || map1->line[i] == 'W')
			{
				if (map1->prev->line[i] == '1')
					return ;
				map1->line[i] = '0';
				map1->prev->line[i] = 'N';
				map_global()->pos_y = map1->i - 1;
				return ;
			}
		}
		map1 = map1->next;
	}
}

void	move_down(int i)
{
	t_map	*map1;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N' || map1->line[i] == 'S' \
				|| map1->line[i] == 'E' || map1->line[i] == 'W')
			{
				if (map1->next->line[i] == '1')
					return ;
				map1->line[i] = '0';
				map1->next->line[i] = 'N';
				map_global()->pos_y = map1->i + 1;
				return ;
			}
		}
		map1 = map1->next;
	}
}

void	move_left(int i)
{
	t_map	*map1;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N' || map1->line[i] == 'S' \
				|| map1->line[i] == 'E' || map1->line[i] == 'W')
			{
				if (map1->line[i -1] == '1')
					return ;
				map1->line[i] = '0';
				map1->line[i -1] = 'N';
				map_global()->pos_x = i - 1;
				return ;
			}
		}
		map1 = map1->next;
	}
}

void	move_right(int i)
{
	t_map	*map1;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N' || map1->line[i] == 'S' \
				|| map1->line[i] == 'E' || map1->line[i] == 'W')
			{
				if (map1->line[i + 1] == '1')
					return ;
				map1->line[i] = '0';
				map1->line[i +1] = 'N';
				map_global()->pos_x = i + 1;
				return ;
			}
		}
		map1 = map1->next;
	}
}

int	key_handler(int key)
{
	int	i;

	i = -1;
	if (key == ESC)
		free_all(0);
	else if (key == W)
		move_up(i);
	else if (key == A)
		move_left(i);
	else if (key == D)
		move_right(i);
	else if (key == S)
		move_down(i);
	else if (key == LAK)
		look_left();
	else if (key == RAK)
		look_right();
	if (key == W || key == A || key == S || key == D || key == LAK \
		|| key == RAK)
		raycasting();
	return (0);
}
