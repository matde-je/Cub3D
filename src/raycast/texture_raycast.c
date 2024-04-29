/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:25:17 by matde-je          #+#    #+#             */
/*   Updated: 2024/04/10 17:13:22 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	get_texture_index(void)
{
	if (ray()->side != 0)
	{
		if (ray()->dir.y > 0)
			tex()->index = SOUTH;
		else
			tex()->index = NORTH;
	}
	else
	{
		if (ray()->dir.y < 0)
			tex()->index = WEST;
		else
			tex()->index = EAST;
	}
}


void	render_textures(int x)
{
	int	y;
	int	color;

	tex()->x = (int)(ray()->wall_x * (double)TEX_SIZE);
	if ((ray()->side == 0 && ray()->dir.x > 0) || (ray()->side == 0
			&& ray()->dir.y < 0))
		tex()->x = TEX_SIZE - tex()->x - 1;
	tex()->step = 1.0 * TEX_SIZE / ray()->line_height;
	tex()->pos = (ray()->render_start - WIN_HEIGHT / 2 + ray()->line_height / 2)
		* tex()->step;
	y = ray()->render_start;
	while (y < ray()->render_end)
	{
		tex()->y = (int)tex()->pos & (TEX_SIZE - 1);
		tex()->pos += tex()->step;
		color = cub3()->tex[tex()->index][TEX_SIZE * tex()->y + tex()->x];
		if (tex()->index == NORTH || tex()->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			tex()->tex_pix[y][x] = color;
		y++;
	}
}
