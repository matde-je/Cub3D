/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:39:08 by matilde           #+#    #+#             */
/*   Updated: 2024/04/22 12:08:49 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// camera looks left
void	look_left(void)
{
	double		oldplanex;
	double		oldirx;
	double		rotspeed;

	rotspeed = 0.05;
	oldirx = player()->dir.x;
	player()->dir.x = player()->dir.x * cos(-rotspeed) - player()->dir.y * sin(-rotspeed);
	player()->dir.y = oldirx * sin(-rotspeed) + player()->dir.y * cos(-rotspeed);
	oldplanex = player()->plane.x;
    player()->plane.x = player()->plane.x * cos(-rotspeed) - player()->plane.y * sin(-rotspeed);
    player()->plane.y = oldplanex * sin(-rotspeed) + player()->plane.y * cos(-rotspeed);
}

// camera look right
void	look_right(void)
{
	double		oldplanex;
	double		oldirx;
	double		rotspeed;

	rotspeed = 0.05;
	oldirx = player()->dir.x;
	player()->dir.x = player()->dir.x * cos(rotspeed) - player()->dir.y * sin(rotspeed);
	player()->dir.y = oldirx * sin(rotspeed) + player()->dir.y * cos(rotspeed);
	oldplanex = player()->plane.x;
    player()->plane.x = player()->plane.x * cos(rotspeed) - player()->plane.y * sin(rotspeed);
    player()->plane.y = oldplanex * sin(rotspeed) + player()->plane.y * cos(rotspeed);
}
