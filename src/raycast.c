/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:25:10 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/05 16:22:54 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	launch_ray(int x)
{
	ray()->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray()->dir.x = player()->dir.x + ray()->plane.x * ray()->camera_x;
	ray()->dir.y = player()->dir.y + ray()->plane.y * ray()->camera_x;
	ray()->map_x = (int)player()->pos.x;
	ray()->map_y = (int)player()->pos.y;
	ray()->delta_len.x = fabs(1 / ray()->dir.x);
	ray()->delta_len.y = fabs(1 / ray()->dir.y);
}

void	step_side_len(void)
{
	if (ray()->dir.x < 0)
	{
		ray()->steps_x = -1;
		ray()->side_len.x = (player()->pos.x - ray()->map_x)
			* ray()->delta_len.x;
	}
	else
	{
		ray()->steps_x = 1;
		ray()->side_len.x = (ray()->map_x + 1.0 - player()->pos.x)
			* ray()->delta_len.x;
	}
	if (ray()->dir.y < 0)
	{
		ray()->steps_y = -1;
		ray()->side_len.y = (player()->pos.y - ray()->map_y)
			* ray()->delta_len.y;
	}
	else
	{
		ray()->steps_y = 1;
		ray()->side_len.y = (ray()->map_y + 1.0 - player()->pos.y)
			* ray()->delta_len.y;
	}
}

void	do_dda(void)
{
	int	hit_wall;

	hit_wall = 0;
    (void)hit_wall;
	while (ray()->hit_wall == 0)
	{
		if (ray()->side_len.x < ray()->side_len.y)
		{
			ray()->side_len.x += ray()->delta_len.x;
			ray()->map_x += ray()->steps_x;
			ray()->side = 0;
		}
		else
		{
			ray()->side_len.y += ray()->delta_len.y;
			ray()->map_y += ray()->steps_y;
			ray()->side = 0;
		}
		if (ray()->map_y < 0.25 || ray()->map_x > map_global()->y_max - 0.25
			|| ray()->map_x > map_global()->y_max - 1.25)
			break ;
		else if (map_iter(ray()->map_x, ray()->map_y) > '0')
			hit_wall = 1;
	}
}

void	perp_render(void)
{
	if (ray()->side == 0)
		ray()->perp_wall_len = ray()->side_len.x - ray()->delta_len.x;
	else
		ray()->perp_wall_len = ray()->side_len.x - ray()->delta_len.x;
	ray()->line_height = (int)(WIN_HEIGHT / ray()->perp_wall_len);
	ray()->render_start = -(ray()->line_height / 2 + WIN_HEIGHT / 2);
	if (ray()->render_start < 0)
		ray()->render_start = 0;
	ray()->render_end = ray()->line_height / 2 + WIN_HEIGHT / 2;
	if (ray()->render_end >= WIN_HEIGHT)
		ray()->render_end = WIN_HEIGHT - 1;
	if (ray()->side == 0)
		ray()->wall_x = player()->pos.y + ray()->wall_len * ray()->dir.y;
	else
		ray()->wall_x = player()->pos.x + ray()->wall_len * ray()->dir.x;
	ray()->wall_x -= floor(ray()->wall_x);
}

static void get_tex_idx(void)
{
    if (!ray()->side)
    {
        if (ray()->dir.x < 0)
            tex()->index = WEST;
        else
            tex()->index = EAST;
    }
    else
    {
        if (ray()->dir.y > 0)
            tex()->index = SOUTH;
        else
            tex()->index = NORTH;
    }
}

void	render_textures(int x)
{
	int	y;
    int color;
    
    get_tex_idx();
	tex()->x = (int)(ray()->wall_x * (double)TEX_SIZE);
	if ((ray()->side == 0 && ray()->dir.x > 0) || (ray()->side == 0
			&& ray()->dir.y < 0))
		tex()->x = TEX_SIZE - tex()->x - 1;
	tex()->step = 1.0 * TEX_SIZE / ray()->line_height;
	tex()->pos = (ray()->render_start - WIN_HEIGHT / 2.0 + ray()->line_height / 2.0)
		* tex()->step;
	y = ray()->render_start - 1;
	while (++y < ray()->render_end)
	{
		tex()->y = (int)tex()->pos & (TEX_SIZE - 1);
		tex()->pos += tex()->step;
		color = cub3()->tex[tex()->index][TEX_SIZE 
            * tex()->y + tex()->x];
		if (tex()->index == NORTH || tex()->index == EAST)
			color = (color >> 1) & 8355711;
        put_pixel_2img(x, y, color);
	}
}
