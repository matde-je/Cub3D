/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:11 by matilde           #+#    #+#             */
/*   Updated: 2024/03/08 17:03:33 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//algorithm of casting rays
//atan2(): returns o inverso da tangent of y/x in radians, dá nos o angulo
void	raycasting(void)
{
	t_map	*map1;
	int		step_x;
	int		step_y;
	float	cur_x;
	float	cur_y;

	map1 = map();
	ray()->x = map_global()->pos_x;
	ray()->y = map_global()->pos_y;
	(ray()->angle) = atan2(ray()->y - map_global()->pos_y, \
	ray()->x - map_global()->pos_x);
	if (ray()->angle < 0)
		ray()->angle += 2 * M_PI;
	step_x = -1;
	if (cos(ray()->angle) >= 0)
		step_x = 1;
	step_y = -1;
	if (sin(ray()->angle) >= 0)
		step_y = 1;
	step_x *= (int)round((cos(ray()->angle)));
	step_y *= (int)round((sin(ray()->angle)));
	cur_x = map_global()->pos_x;
	cur_y = map_global()->pos_y;
	while (map1 && map1->i < map_global()->pos_y)
		map1 = map1->next;
	if (!map1 || map1->i != map_global()->pos_y)
		return ;
	while (cur_x < map1->len && cur_y < map_global()->y_max)
	{
		if (map1->line[(int)round(cur_x)] == '1')
			textur_mapping(cur_x, cur_y);
		cur_x += step_x;
		if (cur_x >= map1->len)
		{
			cur_x = 0;
			cur_y += step_y;
		}
	}
}

//put textures of walls in the window
//i save the position of the camera in the img[pos] accordingly
void	textur_mapping(float cur_x, float cur_y)
{
	int	pos;

	pos = 0;
	(ray()->distance) = sqrt(pow(ray()->x - cur_x, 2) + \
	pow(ray()->y - cur_y, 2));
	if (ray()->x - map_global()->pos_x > 0)
		pos = 'E';
	else if (ray()->x - map_global()->pos_x < 0)
		pos = 'W';
	else if (ray()->y - map_global()->pos_y > 0)
		pos = 'N';
	else if (ray()->y - map_global()->pos_y < 0)
		pos = 'S';
	if (pos != 0)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], round(ray()->x * 32), round(ray()->y * 32));
}

//eucledian distance: 
//sqrt(pow(ray()->x-map_global()->pos_x,2)+pow(ray()->y-map_global()->pos_y,2))