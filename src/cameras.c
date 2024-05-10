/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:39:08 by matilde           #+#    #+#             */
/*   Updated: 2024/05/10 23:41:07 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// camera looks left
void	look_left(void)
{
	float		oldplanex;
	float		oldirx;
	float		rotspeed;

	rotspeed = ROTA_SPEED;
	oldirx = c3d()->p.dir_x;
	c3d()->p.dir_x = c3d()->p.dir_x * cos(-rotspeed) - c3d()->p.dir_y * sin(-rotspeed);
	c3d()->p.dir_y = oldirx * sin(-rotspeed) + c3d()->p.dir_y * cos(-rotspeed);
	oldplanex = c3d()->p.plane_x;
    c3d()->p.plane_x = c3d()->p.plane_x * cos(-rotspeed) - c3d()->p.plane_y * sin(-rotspeed);
    c3d()->p.plane_y = oldplanex * sin(-rotspeed) + c3d()->p.plane_y * cos(-rotspeed);
}

// camera look right
void	look_right(void)
{
	float		oldplanex;
	float		oldirx;
	float		rotspeed;

	rotspeed = ROTA_SPEED;
	oldirx = c3d()->p.dir_x;
	c3d()->p.dir_x = c3d()->p.dir_x * cos(rotspeed) - c3d()->p.dir_y * sin(rotspeed);
	c3d()->p.dir_y = oldirx * sin(rotspeed) + c3d()->p.dir_y * cos(rotspeed);
	oldplanex = c3d()->p.plane_x;
    c3d()->p.plane_x = c3d()->p.plane_x * cos(rotspeed) - c3d()->p.plane_y * sin(rotspeed);
    c3d()->p.plane_y = oldplanex * sin(rotspeed) + c3d()->p.plane_y * cos(rotspeed);
}
