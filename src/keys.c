/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:14:31 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 18:14:35 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	avoid_wall(double x, double y)
{
	if (map_iter((int)y, (int)x) == '1')
		return ;
	c3d()->p.pos_x = x;
	c3d()->p.pos_y = y;
	return ;
}

void	move_up(void)
{
	double	x;
	double	y;

	x = c3d()->p.pos_x + c3d()->p.dir_x * MOVE_SPEED;
	y = c3d()->p.pos_y + c3d()->p.dir_y * MOVE_SPEED;
	return (avoid_wall(x, y));
}

void	move_down(void)
{
	double	x;
	double	y;

	x = c3d()->p.pos_x - c3d()->p.dir_x * MOVE_SPEED;
	y = c3d()->p.pos_y - c3d()->p.dir_y * MOVE_SPEED;
	return (avoid_wall(x, y));
}

void	move_left(void)
{
	double	x;
	double	y;

	x = c3d()->p.pos_x + c3d()->p.dir_y * MOVE_SPEED;
	y = c3d()->p.pos_y - c3d()->p.dir_x * MOVE_SPEED;
	return (avoid_wall(x, y));
}

void	move_right(void)
{
	double	x;
	double	y;

	x = c3d()->p.pos_x - c3d()->p.dir_y * MOVE_SPEED;
	y = c3d()->p.pos_y + c3d()->p.dir_x * MOVE_SPEED;
	return (avoid_wall(x, y));
}

int	key_handler(int key)
{
	if (key == ESC)
		free_all(0);
	else if (key == W)
		move_up();
	else if (key == A)
		move_left();
	else if (key == D)
		move_right();
	else if (key == S)
		move_down();
	else if (key == LAK)
		look_left();
	else if (key == RAK)
		look_right();
	return (0);
}
