/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:55 by matilde           #+#    #+#             */
/*   Updated: 2024/05/15 13:37:19 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>


static void  avoid_wall(double x, double y)
{
    /* if (x < 0.25 
            || x >= c3d()->mg.x_max - 1.25 
            || y < 0.25 
            || y >= c3d()->mg.y_max - 0.25)
        return ; */
    if (map_iter((int)x, (int)y) == '1')
        return ;
    c3d()->p.pos_x = x;
    c3d()->p.pos_y = y;
    return ;
}

void	move_up(int i, t_map *map1)
{
    double x;
    double y;

    (void)map1;
    (void)i;
    x = c3d()->p.pos_x + c3d()->p.dir_x * MOVE_SPEED;
    y = c3d()->p.pos_y + c3d()->p.dir_y * MOVE_SPEED;
    return (avoid_wall(x, y));
	// while (map1)
	// {
	// 	if (map1->i == (int)(c3d()->p.pos_x + c3d()->p.dir_x * MOVE_SPEED))
	// 	{
	// 		i = -1;
	// 		while (++i < map1->len)
	// 		{
	// 			if (i == (int)(c3d()->p.pos_y))
	// 				if (map1->line[i] != 1)
	// 					c3d()->p.pos_x += c3d()->p.dir_x * MOVE_SPEED;
	// 		}
	// 	}
	// 	if (map1->i == (int)(c3d()->p.pos_x))
	// 	{
	// 		i = -1;
	// 		while (++i < map1->len)
	// 		{
	// 			if (i == (int)(c3d()->p.pos_y + c3d()->p.dir_y * MOVE_SPEED))
	// 				if (map1->line[i] != 1)
	// 					c3d()->p.pos_y += c3d()->p.dir_y * MOVE_SPEED;
	// 		}
	// 	}
	// 	map1 = map1->next;
	// }

}

void	move_down(int i, t_map *map1)
{

    double x;
    double y;

    (void)map1;
    (void)i;
    x = c3d()->p.pos_x - c3d()->p.dir_x * MOVE_SPEED;
    y = c3d()->p.pos_y -  c3d()->p.dir_y * MOVE_SPEED;
    return (avoid_wall(x, y));
	/* while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos_x - c3d()->p.dir_x * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos_y))
					if (map1->line[i] != 1)
						c3d()->p.pos_x -= c3d()->p.dir_x * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos_x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos_y - c3d()->p.dir_y * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos_y -= c3d()->p.dir_y * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	} */
}

void	move_left(int i, t_map *map1)
{

    double x;
    double y;

    (void)map1;
    (void)i;
    x = c3d()->p.pos_x + c3d()->p.dir_y * MOVE_SPEED;
    y = c3d()->p.pos_y - c3d()->p.dir_x * MOVE_SPEED;
    return (avoid_wall(x, y));
	/* while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos_x + c3d()->p.dir_y * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos_y))
					if (map1->line[i] != 1)
						c3d()->p.pos_x += c3d()->p.dir_y * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos_x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos_y + c3d()->p.dir_x * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos_y += c3d()->p.dir_x * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	} */
}

void	move_right(int i, t_map *map1)
{

    double x;
    double y;

    (void)map1;
    (void)i;
    x = c3d()->p.pos_x - c3d()->p.dir_y * MOVE_SPEED;
    y = c3d()->p.pos_y + c3d()->p.dir_x * MOVE_SPEED;
    return (avoid_wall(x, y));
	/* while (map1)
	{
		if (map1->i == (int)(c3d()->p.pos_x - c3d()->p.dir_y * MOVE_SPEED))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos_y))
					if (map1->line[i] != 1)
						c3d()->p.pos_x -= c3d()->p.dir_y * MOVE_SPEED;
			}
		}
		if (map1->i == (int)(c3d()->p.pos_x))
		{
			i = -1;
			while (++i < map1->len)
			{
				if (i == (int)(c3d()->p.pos_y - c3d()->p.dir_x * MOVE_SPEED))
					if (map1->line[i] != 1)
						c3d()->p.pos_y -= c3d()->p.dir_x * MOVE_SPEED;
			}
		}
		map1 = map1->next;
	} */
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
