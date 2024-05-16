/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:13:30 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 19:34:46 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_values(double dir_x, double dir_y, double plane_x,
		double plane_y)
{
	c3d()->p.dir_x = dir_x;
	c3d()->p.dir_y = dir_y;
	c3d()->p.plane_x = plane_x;
	c3d()->p.plane_y = plane_y;
}

void	init_start(int x, int y)
{
	c3d()->p.pos_x = (double)y + 0.5;
	c3d()->p.pos_y = (double)x + 0.5;
	if (map_iter(x, y) == 'N')
		set_player_values(0, -1, 0.66, 0);
	else if (map_iter(x, y) == 'S')
		set_player_values(0, 1, -0.66, 0);
	else if (map_iter(x, y) == 'E')
		set_player_values(1, 0, 0, 0.66);
	else if (map_iter(x, y) == 'W')
		set_player_values(1, 0, 0, -0.66);
}

void	avoid_wall(double x, double y)
{
	if (map_iter((int)y, (int)x) == '1')
		return ;
	c3d()->p.pos_x = x;
	c3d()->p.pos_y = y;
	return ;
}
