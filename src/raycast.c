/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:25:10 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/11 02:29:40 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

void	launch_ray(int x)
{
	c3d()->r.camera_x = 2 * x / (float)WIN_WIDTH - 1;
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
		c3d()->r.side_len_x = (c3d()->p.pos_x - c3d()->r.map_x)
			* c3d()->r.delta_len_x;
	}
	else
	{
		c3d()->r.steps_x = 1;
		c3d()->r.side_len_x = (c3d()->r.map_x + 1.0 - c3d()->p.pos_x)
			* c3d()->r.delta_len_x;
	}
	if (c3d()->r.dir_y < 0)
	{
		c3d()->r.steps_y = -1;
		c3d()->r.side_len_y = (c3d()->p.pos_y - c3d()->r.map_y)
			* c3d()->r.delta_len_y;
	}
	else
	{
		c3d()->r.steps_y = 1;
		c3d()->r.side_len_y = (c3d()->r.map_y + 1.0 - c3d()->p.pos_y)
			* c3d()->r.delta_len_y;
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
		if (c3d()->r.map_y < 0.25 
				|| c3d()->r.map_x < 0.25
				|| c3d()->r.map_y > c3d()->mg.y_max - 0.25
				|| c3d()->r.map_x > c3d()->mg.x_max - 1.25)
				break ;
		else if (map_iter(c3d()->r.map_x, c3d()->r.map_y) == '0')
			c3d()->r.hit_wall = 1;
	}
}

void	perp_render(void)
{
	if (c3d()->r.side == 0)
		c3d()->r.wall_len = c3d()->r.side_len_x - c3d()->r.delta_len_x;
	else
		c3d()->r.wall_len = c3d()->r.side_len_y - c3d()->r.delta_len_y;
	c3d()->r.line_height = (int)(WIN_HEIGHT / c3d()->r.wall_len);
	c3d()->r.render_start = -(c3d()->r.line_height / 2 + WIN_HEIGHT / 2);
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

static void get_tex_idx(void)
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

void	render_textures(int x)
{
	int	y;
    int color;
    
    get_tex_idx();
	c3d()->t.x = (int)(c3d()->r.wall_x * (float)TEX_SIZE);
	if ((c3d()->r.side == 0 && c3d()->r.dir_x < 0) || (c3d()->r.side == 1
			&& c3d()->r.dir_y > 0))
		c3d()->t.x = TEX_SIZE - c3d()->t.x - 1;
	c3d()->t.step = 1.0 * TEX_SIZE / c3d()->r.line_height;
	c3d()->t.pos = (c3d()->r.render_start - WIN_HEIGHT / 2.0 + c3d()->r.line_height / 2.0)
		* c3d()->t.step;
	y = c3d()->r.render_start - 1;
	while (++y < c3d()->r.render_end)
	{
		c3d()->t.y = (int)c3d()->t.pos & (TEX_SIZE - 1);
		c3d()->t.pos += c3d()->t.step;
		color = c3d()->tex[c3d()->t.index][TEX_SIZE 
            * c3d()->t.y + c3d()->t.x];
		if (c3d()->t.index == NORTH || c3d()->t.index == EAST)
			color = (color >> 1) & 8355711;
        ft_printf("%d\n", color);
        put_pixel_2img(x, y, color);
	}
}
