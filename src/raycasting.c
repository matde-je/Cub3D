/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:11 by matilde           #+#    #+#             */
/*   Updated: 2024/03/07 11:25:25 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//calculate updated ray angle if cameras moved
void	calculate_ray_angle(void)
{
	t_map	*map1;

	map1 = map();
	while (map1 && map1->i < map_global()->pos_y)
			map1 = map1->next;
	if (!map1 || map1->i != map_global()->pos_y)
		return ;
	if (ray()->angle == 0 && map1->line[map_global()->pos_x] != 'N')
		ray()->angle = map1->line[map_global()->pos_x];
	else if (ray()->angle == 180 && map1->line[map_global()->pos_x] != 'S')
		ray()->angle = map1->line[map_global()->pos_x];
	else if (ray()->angle == 90 && map1->line[map_global()->pos_x] != 'E')
		ray()->angle = map1->line[map_global()->pos_x];
	else if (ray()->angle == 270 && map1->line[map_global()->pos_x] != 'W')
		ray()->angle = map1->line[map_global()->pos_x];
}

//calculate initial, from start ray angle
void	ray_angle(void)
{
	t_map	*map1;
	int		i;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N')
				ray()->angle = 0;
			else if (map1->line[i] == 'S')
				ray()->angle = 180;
			else if (map1->line[i] == 'E')
				ray()->angle = 90;
			else if (map1->line[i] == 'W')
				ray()->angle = 270;
		}
		map1 = map1->next;
	}
}

//coordenates from where the ray starts and finishes,
//limits of the map according to the orientation of the camera
void	coordenates(int *z, int *y, int *x)
{
	t_map	*map1;

	map1 = map();
	while (map1 && map1->i < map_global()->pos_y)
			map1 = map1->next;
	if (!map1 || map1->i != map_global()->pos_y)
		return ;
	if (ray()->angle && ray()->angle == 0)
		*z = map1->i;
	else
		*z = map_global()->y_max;
	if (ray()->angle == 180)
		*y = (map_global()->y_max / 2) - 1;
	if (ray()->angle == 90)
		*x = (map_global()->x_max / 2) - 1;
	if (ray()->angle == 270)
		*x = (map_global()->x_max / 2) - 1;
}

//algorithm
void	raycasting(void)
{
	t_map	*map1;
	int		z;
	int		y;
	int		x;
	int		max_distance = 100;

	x = -1;
	y = -1;
	map1 = map();
	ray_angle();
	coordenates(&z, &y, &x);
	while (++y < z)
	{
		calculate_ray_angle();
		coordenates(&z, &y, &x);
		while (++x < map_global()->x_max)
		{
			ray()->x = map_global()->pos_x;
			ray()->y = map_global()->pos_y;
			float ray_dx = cos(ray()->angle);
			float ray_dy = sin(ray()->angle);
			(ray()->distance) = sqrt(pow(ray()->x - map_global()->pos_x, 2) + \
			pow(ray()->y - map_global()->pos_y, 2));
			while (!ray()->hit_wall && ray()->distance < max_distance)
			{
				ray()->x += ray_dx;
				ray()->y += ray_dy;
				while (map1 && map1->i != (int)ray()->y)
					map1 = map1->next;
				if (map1->i == (int)ray()->y && map1->line[(int)ray()->x] == '1')
					ray()->hit_wall = 1;
				ray()->distance += 0.1;
			}
			textur_mapping(map1);
			//map1 = map();
		}
	}
}

//put textures of walls in the window
//i save the position of the camera in the img[pos] accordingly
void	textur_mapping(t_map *map1)
{
	int	pos;

	pos = 0;
	if (ray()->hit_wall == 0)
		return ;
	ray()->hit_wall = 0;
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
		window()->img[pos], (int)ray()->x * 32, map1->i * 32);
}

//eucledian distance: 
//sqrt(pow(ray()->x-map_global()->pos_x,2)+pow(ray()->y-map_global()->pos_y,2))