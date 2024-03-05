/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:37 by matilde           #+#    #+#             */
/*   Updated: 2024/03/05 17:49:02 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//display the window
void	new_window(void)
{
	window()->mlx = mlx_init();
	if (!window()->mlx)
		free_all(0);
	(window()->window_ptr) = mlx_new_window(window()->mlx, \
	map_global()->x_max * 32, map_global()->y_max * 32, "have fun");
	if (!window()->window_ptr)
		free_all(0);
	img_func();
}

//loads the textures of the walls to img['orientation']
void	img_func(void)
{
	int	h;
	int	w;

	h = 32;
	w = 32;
	(window()->img['N']) = mlx_xpm_file_to_image(window()->mlx, \
	"./textures/HEDGE.xpm", &w, &h);
	(window()->img['S']) = mlx_xpm_file_to_image(window()->mlx, \
	"./textures/SLIME.xpm", &w, &h);
	(window()->img['W']) = mlx_xpm_file_to_image(window()->mlx, \
	"./textures/SLUDGE.xpm", &w, &h);
	(window()->img['E']) = mlx_xpm_file_to_image(window()->mlx, \
	"./textures/WARN.xpm", &w, &h);
	put_cf_colors();
}

//puts in window the ceiling and floor colors, pixel by pixel (slow proccess)
void	put_cf_colors(void)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (map_global()->y_max * 32) / 2)
	{
		x = -1;
		while (++x < (map_global()->x_max * 32))
			mlx_pixel_put(window()->mlx, window()->window_ptr, x, y, \
			texture()->c[3]);
	}
	y = (map_global()->y_max * 32) / 2;
	while (++y < (map_global()->y_max * 32))
	{
		x = -1;
		while (++x < (map_global()->x_max * 32))
			mlx_pixel_put(window()->mlx, window()->window_ptr, x, y, \
			texture()->f[3]);
	}
	raycasting();
}

//put image of the texture orientation to the window
void	textur_mapping(void)
{
	int	pos;

	pos = 0;
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
		window()->img[pos], map_global()->x_max * 32, map_global()->y_max * 32);
	raycasting();
}

//algorithm
void	raycasting(void)
{
	float	step;
	int		max;

	step = 0.1;
	max = 100;
	printf("map %i\n", map_global()->pos_x);
	ray()->x = map_global()->pos_x;
	ray()->y = map_global()->pos_y;
	while (1)
	{
		if (sqrt(pow(ray()->x - map_global()->pos_x, 2) + \
			pow(ray()->y - map_global()->pos_y, 2)) < 0.1)
			break ;
		if (sqrt(pow(ray()->x - map_global()->pos_x, 2) + \
			pow(ray()->y - map_global()->pos_y, 2)) > max)
			return ;
		ray()->x += step;
		ray()->y += step;
	}
	textur_mapping();
}

//eucledian distance: 
//sqrt(pow(ray()->x-map_global()->pos_x,2)+pow(ray()->y-map_global()->pos_y,2))