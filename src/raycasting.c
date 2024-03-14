/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:11 by matilde           #+#    #+#             */
/*   Updated: 2024/03/14 22:15:12 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_angle(void)
{
	t_map	*map1;
	int		i;
	int		player_angle;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N')
				player_angle = 0;
			else if (map1->line[i] == 'S')
				player_angle = 180;
			else if (map1->line[i] == 'E')
				player_angle = 90;
			else if (map1->line[i] == 'W')
				player_angle = 270;
		}
		map1 = map1->next;
	}
	return (player_angle);
}

void	raycasting(void)
{
	float	horizontal_x;
	float	horizontal_y;
	float	horizontal_distance;
	float	vertical_distance;
	float	intersect_x;
	float	intersect_y;
	float	vertical_x;
	float	vertical_y;
	t_map	*map1;
	int		column;

	map1 = map();
	column = -1;
	while (++column < map1->len)
	{
		horizontal_colision(column, &horizontal_x, &horizontal_y, map1);
		vertical_colision(column, &vertical_x, &vertical_y, map1);
		horizontal_distance = distance(map_global()->pos_x, horizontal_x, \
		map_global()->pos_y, horizontal_y);
		vertical_distance = distance(map_global()->pos_x, vertical_x, \
		map_global()->pos_y, vertical_y);
		intersect_x = vertical_x;
		intersect_y = vertical_y;
		if (horizontal_distance < vertical_distance)
		{
			intersect_x = horizontal_x;
			intersect_y = horizontal_y;
		}
		if (intersect_x != 0 && intersect_y != 0)
		{
			calculate_ray_angle(intersect_x, intersect_y);
			if (horizontal_distance < vertical_distance)
				render(column, intersect_x, intersect_y, horizontal_distance);
			else
				render(column, intersect_x, intersect_y, vertical_distance);
		}
		map1 = map1->next;
	}
}

void	horizontal_colision(int j, float *horizontal_x, \
	float *horizontal_y, t_map *map1)
{
	horizontal_x = 0;
	horizontal_y = 0;
	while (++j < map1->len)
	{
		if (map1->line[j] == '1')
		{
			*horizontal_x = j;
			*horizontal_y = map1->i;
			break ;
		}
	}
}

void	vertical_colision(int j, float *vertical_x, \
	float *vertical_y, t_map *map1)
{
	int	column;

	column = j;
	vertical_x = 0;
	vertical_y = 0;
	while (++j < map_global()->y_max)
	{
		if (map1->line[column] == '1')
		{
			*vertical_x = column;
			*vertical_y = j;
			break ;
		}
		map1 = map1->next;
	}
}

void	calculate_ray_angle(float intersect_x, float intersect_y)
{
	(ray()->angle) = atan2(distance(0, 0, intersect_y, map_global()->pos_y), \
	distance(intersect_x, map_global()->pos_x, 0, 0));
}

float	distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int	calculate_texture_index(float intersect_x, float intersect_y)
{
	int	pos;
	int	player;

	pos = -1;
	player = player_angle();
	if (player == 0)
	{
		pos = 'N';
		if (intersect_x < map_global()->pos_x)
			pos = 'W';
		else if (intersect_x > map_global()->pos_x)
			pos = 'E';
	}
	else if (player == 180)
	{
		pos = 'S';
		if (intersect_x < map_global()->pos_x)
			pos = 'E';
		else if (intersect_x > map_global()->pos_x)
			pos = 'W';
	}
	else if (player == 90)
	{
		pos = 'E';
		if (intersect_y > map_global()->pos_y)
			pos = 'N';
		else if (intersect_y < map_global()->pos_y)
			pos = 'S';
	}
	else if (player == 270)
	{
		pos = 'W';
		if (intersect_y > map_global()->pos_y)
			pos = 'N';
		else if (intersect_y < map_global()->pos_y)
			pos = 'S';
	}
	return (pos);
}

void	render(int column, float intersect_x, float intersect_y, float distance)
{
	int		wall_height;
	int		wall_top;
	int		pos;
	//int		wall_bottom;

	wall_height = (int)(map_global()->y_max / distance);
	wall_top = (map_global()->y_max - wall_height) / 2;
	//wall_bottom = wall_top + wall_height;
	pos = calculate_texture_index(intersect_x, intersect_y);
	if (pos == -1)
		return ;
	mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
	window()->img[pos], column, wall_top);
}
