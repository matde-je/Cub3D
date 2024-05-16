/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:13:44 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 19:38:26 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_2img(int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	*(int *)&c3d()->image.addr[(y * c3d()->image.size) + (x * (c3d()->image.bpp
				/ 8))] = color;
}

void	render_floor(void)
{
	int	y;
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2 - 1;
		while (++y < WIN_HEIGHT)
			put_pixel_2img(x, y, c3d()->t.f[3]);
	}
}

void	render_ceiling(void)
{
	int	y;
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
			put_pixel_2img(x, y, c3d()->t.c[3]);
	}
}

void	raycasting(void)
{
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		launch_ray(x);
		step_side_len();
		do_dda();
		perp_render();
		render_textures(x);
	}
}

void	render_textures(int x)
{
	int				y;
	unsigned int	color;

	c3d()->t.x = (int)(c3d()->r.wall_x * TEX_SIZE);
	if ((c3d()->r.side == 0 && c3d()->r.dir_x < 0) || (c3d()->r.side == 1
			&& c3d()->r.dir_y > 0))
		c3d()->t.x = TEX_SIZE - c3d()->t.x - 1;
	c3d()->t.step = 1.0 * TEX_SIZE / c3d()->r.line_height;
	c3d()->t.pos = (c3d()->r.render_start - WIN_HEIGHT / 2 \
			+ c3d()->r.line_height / 2) * c3d()->t.step;
	y = c3d()->r.render_start - 1;
	while (++y < c3d()->r.render_end)
	{
		c3d()->t.y = (int)c3d()->t.pos & (TEX_SIZE - 1);
		c3d()->t.pos += c3d()->t.step;
		color = c3d()->tex[c3d()->t.index][TEX_SIZE * c3d()->t.y + c3d()->t.x];
		if (c3d()->r.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel_2img(x, y, color);
	}
}
