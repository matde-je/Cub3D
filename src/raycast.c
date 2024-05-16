/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:25:10 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 19:38:06 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	launch_ray(int x)
{
	c3d()->r.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	c3d()->r.dir_x = c3d()->p.dir_x + c3d()->p.plane_x * c3d()->r.camera_x;
	c3d()->r.dir_y = c3d()->p.dir_y + c3d()->p.plane_y * c3d()->r.camera_x;
	c3d()->r.map_x = (int)c3d()->p.pos_x;
	c3d()->r.map_y = (int)c3d()->p.pos_y;
	c3d()->r.hit_wall = 0;
	c3d()->r.delta_len_x = fabs(1 / c3d()->r.dir_x);
	c3d()->r.delta_len_y = fabs(1 / c3d()->r.dir_y);
}

void	step_side_len(void)
{
	if (c3d()->r.dir_x < 0)
	{
		c3d()->r.steps_x = -1;
		c3d()->r.side_len_x = (c3d()->p.pos_x - c3d()->r.map_x) \
			* c3d()->r.delta_len_x;
	}
	else
	{
		c3d()->r.steps_x = 1;
		c3d()->r.side_len_x = (c3d()->r.map_x + 1.0 - c3d()->p.pos_x) \
			* c3d()->r.delta_len_x;
	}
	if (c3d()->r.dir_y < 0)
	{
		c3d()->r.steps_y = -1;
		c3d()->r.side_len_y = (c3d()->p.pos_y - c3d()->r.map_y) \
			* c3d()->r.delta_len_y;
	}
	else
	{
		c3d()->r.steps_y = 1;
		c3d()->r.side_len_y = (c3d()->r.map_y + 1.0 - c3d()->p.pos_y) \
			* c3d()->r.delta_len_y;
	}
}

static void	get_tex_idx(void)
{
	if (!c3d()->r.side)
	{
		if (c3d()->r.dir_x < 0)
			c3d()->t.index = WEST;
		else
			c3d()->t.index = EAST;
	}
	else
	{
		if (c3d()->r.dir_y > 0)
			c3d()->t.index = SOUTH;
		else
			c3d()->t.index = NORTH;
	}
}

void	do_dda(void)
{
	while (c3d()->r.hit_wall == 0)
	{
		if (c3d()->r.side_len_x < c3d()->r.side_len_y)
		{
			c3d()->r.side_len_x += c3d()->r.delta_len_x;
			c3d()->r.map_x += c3d()->r.steps_x;
			c3d()->r.side = 0;
		}
		else
		{
			c3d()->r.side_len_y += c3d()->r.delta_len_y;
			c3d()->r.map_y += c3d()->r.steps_y;
			c3d()->r.side = 1;
		}
		if (map_iter(c3d()->r.map_y, c3d()->r.map_x) == '1')
		{
			c3d()->r.hit_wall = 1;
			get_tex_idx();
		}
	}
}

void	perp_render(void)
{
	if (c3d()->r.side == 0)
		c3d()->r.wall_len = c3d()->r.side_len_x - c3d()->r.delta_len_x;
	else
		c3d()->r.wall_len = c3d()->r.side_len_y - c3d()->r.delta_len_y;
	c3d()->r.line_height = (int)(WIN_HEIGHT / c3d()->r.wall_len);
	c3d()->r.render_start = -1 * (c3d()->r.line_height / 2) + (WIN_HEIGHT / 2);
	if (c3d()->r.render_start < 0)
		c3d()->r.render_start = 0;
	c3d()->r.render_end = c3d()->r.line_height / 2 + WIN_HEIGHT / 2;
	if (c3d()->r.render_end >= WIN_HEIGHT)
		c3d()->r.render_end = WIN_HEIGHT - 1;
	if (c3d()->r.side == 0)
		c3d()->r.wall_x = c3d()->p.pos_y + c3d()->r.wall_len * c3d()->r.dir_y;
	else
		c3d()->r.wall_x = c3d()->p.pos_x + c3d()->r.wall_len * c3d()->r.dir_x;
	c3d()->r.wall_x -= floor(c3d()->r.wall_x);
}
