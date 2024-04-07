/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:25:17 by matde-je          #+#    #+#             */
/*   Updated: 2024/04/07 14:50:53 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	render_textures(int x)
{
	int		y;
	double	step;

	step = 0;
	cub3()->ray.wall_x = 0;
	if (cub3()->ray.side == 0)
		cub3()->ray.wall_x = map_global()->py + cub3()->ray.perp_wall_len
			* cub3()->ray.ray_dir.x;
	else
		cub3()->ray.wall_x = map_global()->px + cub3()->ray.perp_wall_len
			* cub3()->ray.ray_dir.x;
	cub3()->ray.wall_x = floor(cub3()->ray.wall_x);
	cub3()->ray.tex_x = (int)(cub3()->ray.wall_x * (double)TEX_SIZE);
	if (cub3()->ray.side == 0 && cub3()->ray.ray_dir.x > 0)
		cub3()->ray.tex_x = TEX_SIZE - cub3()->ray.tex_x - 1;
	if (cub3()->ray.side == 0 && cub3()->ray.ray_dir.y < 0)
		cub3()->ray.tex_x = TEX_SIZE - cub3()->ray.tex_x - 1;
	// vertical texture stripe
	step = 1.0 * TEX_SIZE / cub3()->ray.line_height;
	cub3()->ray.texture_pos = (cub3()->ray.render_start - WIN_HEIGHT / 2
			+ cub3()->ray.line_height / 2) * step;
	cub3()->ray.y = cub3()->ray.render_start;
	while (y < cub3()->ray.render_end)
	{
		cub3()->ray.tex_y = (int)cub3()->ray.texture_pos & (TEX_SIZE - 1);
		cub3()->ray.texture_pos += step;
	}
}

void render_vert_text(int x)
{
    int y;
    double step;
    double tex_pos;
    unsigned int color;

    color = 0;
    step = 1.0 * TEX_SIZE / cub3()->ray.line_height;
    tex_pos = (cub3()->ray.render_start - WIN_HEIGHT / 2 \
            + cub3()->ray.line_height / 2) * step;
    y = cub3()->ray.render_start - 1;
    while (++y < cub3()->ray.render_end)
    {
        cub3()->ray.tex_y = (int)tex_pos & (TEX_SIZE -1);
        tex_pos += step;
        color = cub3()->tex_arr[10][TEX_SIZE * cub3()->ray.tex_y \
        + cub3()->ray.tex_x];
        if (cub3()->ray.side == 1)
            color = (color >> 1) & 8355711;
        put_pixel_2img(x, y, color);
    }
}

void raycasting(void)
{
    int x;

    x = -1;
    while (++x < WIN_WIDTH)
    {
        launch_ray(x);
        dda();
        step_side_len_x();
        step_side_len_y();
        perp_render();
        render_textures(x);
        render_vert_text(x);
    }
}
