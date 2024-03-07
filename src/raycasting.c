/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:41:11 by matilde           #+#    #+#             */
/*   Updated: 2024/03/07 13:24:55 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//if cameras moved, the ray angle is updated
void	ray_angle(t_map *map1)
{
	if (map1->line[map_global()->pos_x] == 'N' - 32)
		ray()->angle = 270;
	else if (map1->line[map_global()->pos_x] == 'N' + 32)
		ray()->angle = 90;
	else if (map1->line[map_global()->pos_x] == 'S' + 32)
		ray()->angle = 270;
	else if (map1->line[map_global()->pos_x] == 'S' - 32)
		ray()->angle = 90;
	else if (map1->line[map_global()->pos_x] == 'E' - 32)
		ray()->angle = 0;
	else if (map1->line[map_global()->pos_x] == 'E' + 32)
		ray()->angle = 180;
	else if (map1->line[map_global()->pos_x] == 'W' + 32)
		ray()->angle = 0;
	else if (map1->line[map_global()->pos_x] == 'W' - 32)
		ray()->angle = 180;
}

//calculate initial ray angle
void	calculate_ray_angle(int z, int y, int x)
{
	t_map	*map1;

	map1 = map();
	while (map1 && map1->i < map_global()->pos_y)
			map1 = map1->next;
	if (!map1 || map1->i != map_global()->pos_y)
		return ;
	if (map1->line[map_global()->pos_x] == 'N')
		ray()->angle = 0;
	else if (map1->line[map_global()->pos_x] == 'S')
		ray()->angle = 180;
	else if (map1->line[map_global()->pos_x] == 'E')
		ray()->angle = 90;
	else if (map1->line[map_global()->pos_x] == 'W')
		ray()->angle = 270;
	else
		ray_angle(map1);
	coordenates(&z, &y, &x, 0);
}

//coordenates from where the ray starts and finishes,
//limits of the map according to the orientation of the camera
void	coordenates(int *z, int *y, int *x, int a)
{
	t_map	*map1;

	map1 = map();
	while (map1 && map1->i < map_global()->pos_y)
			map1 = map1->next;
	if (!map1 || map1->i != map_global()->pos_y)
		return ;
	if (a == 1 && ray()->angle == 90)
		*x = map_global()->pos_x;
	else if (a == 1)
		*x = -1;
	if (a == 1)
		return ;
	if (ray()->angle && ray()->angle == 0)
		*z = map1->i;
	else
		*z = map_global()->y_max;
	if (ray()->angle == 180)
		*y = map1->i;
}

//algorithm
void	raycasting(int z, int y, int x)
{
	t_map	*map1;
	float	ray_dx;
	float	ray_dy;

	map1 = map();
	calculate_ray_angle(z, y, x);
	while (++y < z)
	{
		coordenates(&z, &y, &x, 1);
		while (++x < map_global()->x_max)
		{
			ray()->x = map_global()->pos_x;
			ray()->y = map_global()->pos_y;
			ray_dx = cos(ray()->angle);
			ray_dy = sin(ray()->angle);
			(ray()->distance) = sqrt(pow(ray()->x - map_global()->pos_x, 2) + \
			pow(ray()->y - map_global()->pos_y, 2));
			while (map1 && !ray()->hit_wall && ray()->distance < 100)
			{
				ray()->x += ray_dx;
				ray()->y += ray_dy;
				while (map1 && map1->i != (int)ray()->y)
					map1 = map1->next;
				if (map1 && map1->i == (int)ray()->y \
					&& map1->line[(int)ray()->x] == '1')
					ray()->hit_wall = 1;
				ray()->distance += 0.1;
			}
			textur_mapping(map1);
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