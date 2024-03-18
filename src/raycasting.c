/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:24:41 by matilde           #+#    #+#             */
/*   Updated: 2024/03/18 12:05:11 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	raycasting(void)
{
	t_map	*map1;
	int		column;

	map1 = map();
	column = -1;
	while (map1 && ++column < map_global()->x_max)
	{
		horizontal_colision(column, map1);
		map1 = map1->next;
	}
}

void	horizontal_colision(int j, t_map *map1)
{
	float	horizontal_x;
	float	horizontal_y;
	float	dist;
	int		column;

	horizontal_x = 0;
	horizontal_y = 0;
	column = j;
	while (++j < map1->len)
	{
		if (map1->line[j] == '1')
		{
			horizontal_x = j;
			horizontal_y = map1->i;
			break ;
		}
	}
	(dist) = distance(map_global()->pos_x, horizontal_x, map_global()->pos_y, \
		horizontal_y);
	ray()->intersect_x = horizontal_x;
	ray()->intersect_y = horizontal_y;
	vertical_colision(&dist, column, map1, 0);
	render_cube(dist);
}

void	vertical_colision(float *dist, int j, t_map *map1, int column)
{
	float	vertical_x;
	float	vertical_y;
	float	dist2;

	column = j;
	vertical_x = 0;
	vertical_y = 0;
	while (++j < map_global()->y_max)
	{
		if (map1->line[column] == '1')
		{
			vertical_x = column;
			vertical_y = j;
			break ;
		}
		map1 = map1->next;
	}
	dist2 = distance(map_global()->pos_x, vertical_x, map_global()->pos_y, \
		vertical_y);
	if (dist2 < *dist)
	{
		ray()->intersect_x = vertical_x;
		ray()->intersect_y = vertical_y;
		*dist = dist2;
	}
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

// void	calculate_ray_angle(float ray()->intersect_x, float ray()->intersect_y)
// {
// 	(ray()->angle) = atan2(distance(0, 0, ray()->intersect_y,
// map_global()->pos_y),
// 	distance(ray()->intersect_x, map_global()->pos_x, 0, 0));
// }