/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:39:08 by matilde           #+#    #+#             */
/*   Updated: 2024/05/08 20:25:50 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// camera looks left
void	look_left(void)
{
	double		oldplanex;
	double		oldirx;
	double		rotspeed;

	rotspeed = ROTA_SPEED;
	oldirx = c3d()->p.dir.x;
	c3d()->p.dir.x = c3d()->p.dir.x * cos(-rotspeed) - c3d()->p.dir.y * sin(-rotspeed);
	c3d()->p.dir.y = oldirx * sin(-rotspeed) + c3d()->p.dir.y * cos(-rotspeed);
	oldplanex = c3d()->p.plane.x;
    c3d()->p.plane.x = c3d()->p.plane.x * cos(-rotspeed) - c3d()->p.plane.y * sin(-rotspeed);
    c3d()->p.plane.y = oldplanex * sin(-rotspeed) + c3d()->p.plane.y * cos(-rotspeed);
}

// camera look right
void	look_right(void)
{
	double		oldplanex;
	double		oldirx;
	double		rotspeed;

	rotspeed = ROTA_SPEED;
	oldirx = c3d()->p.dir.x;
	c3d()->p.dir.x = c3d()->p.dir.x * cos(rotspeed) - c3d()->p.dir.y * sin(rotspeed);
	c3d()->p.dir.y = oldirx * sin(rotspeed) + c3d()->p.dir.y * cos(rotspeed);
	oldplanex = c3d()->p.plane.x;
    c3d()->p.plane.x = c3d()->p.plane.x * cos(rotspeed) - c3d()->p.plane.y * sin(rotspeed);
    c3d()->p.plane.y = oldplanex * sin(rotspeed) + c3d()->p.plane.y * cos(rotspeed);
}
