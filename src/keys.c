/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:55 by matilde           #+#    #+#             */
/*   Updated: 2024/05/08 14:59:49 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos.x + c3d()->p.dir.x * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y))
					if (map1->line[i] != 1)
						c3d()->p.pos.x += c3d()->p.dir.x * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y + c3d()->p.dir.y * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos.y += c3d()->p.dir.y * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

void	move_down(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos.x - c3d()->p.dir.x * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y))
					if (map1->line[i] != 1)
						c3d()->p.pos.x -= c3d()->p.dir.x * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y - c3d()->p.dir.y * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos.y -= c3d()->p.dir.y * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

void	move_left(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos.x - c3d()->p.dir.y * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y))
					if (map1->line[i] != 1)
						c3d()->p.pos.x -= c3d()->p.dir.y * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y - c3d()->p.dir.x * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos.y -= c3d()->p.dir.x * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

void	move_right(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos.x + c3d()->p.dir.y * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y))
					if (map1->line[i] != 1)
						c3d()->p.pos.x += c3d()->p.dir.y * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos.y + c3d()->p.dir.x * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos.y += c3d()->p.dir.x * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

int	key_handler(int key)
{
	t_map	*map1;

	map1 = map();
	if (key == ESC)
		free_all(0);
	else if (key == W)
		move_up(0, map1);
	else if (key == A)
		move_left(0, map1);
	else if (key == D)
		move_right(0, map1);
	else if (key == S)
		move_down(0, map1);
	else if (key == LAK)
		look_left();
	else if (key == RAK)
		look_right();
	return (0);
}
