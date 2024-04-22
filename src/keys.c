/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:55 by matilde           #+#    #+#             */
/*   Updated: 2024/04/22 12:12:55 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(player()->pos.x + player()->dir.x * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y))
					if (map1->line[i] != 1)
						player()->pos.x += player()->dir.x * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(player()->pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y + player()->dir.y * MOVE_SPEED))
					if (map1->line[i] != 1)
						player()->pos.y += player()->dir.y * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

void	move_down(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(player()->pos.x - player()->dir.x * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y))
					if (map1->line[i] != 1)
						player()->pos.x -= player()->dir.x * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(player()->pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y - player()->dir.y * MOVE_SPEED))
					if (map1->line[i] != 1)
						player()->pos.y -= player()->dir.y * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

void	move_left(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(player()->pos.x - player()->dir.y * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y))
					if (map1->line[i] != 1)
						player()->pos.x -= player()->dir.y * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(player()->pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y - player()->dir.x * MOVE_SPEED))
					if (map1->line[i] != 1)
						player()->pos.y -= player()->dir.x * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	}
}

void	move_right(int i, t_map *map1)
{
	while (map1)
	{
		if (map1->i == (int)(player()->pos.x + player()->dir.y * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y))
					if (map1->line[i] != 1)
						player()->pos.x += player()->dir.y * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(player()->pos.x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(player()->pos.y + player()->dir.x * MOVE_SPEED))
					if (map1->line[i] != 1)
						player()->pos.y += player()->dir.x * MOVE_SPEED;
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
