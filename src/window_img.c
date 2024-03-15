/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:37 by matilde           #+#    #+#             */
/*   Updated: 2024/03/15 14:07:17 by matilde          ###   ########.fr       */
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

// void	put_cf_colors(void)
// {
// 	int	y;
// 	int	x;
//     int color1;
//     int color2;

//     color1 = texture()->c[0] << 16 | texture()->c[1]<< 8 | texture()->c[2];
//     color2 = texture()->f[0] << 16 | texture()->f[1]<< 8 | texture()->f[2];
// 	x = -1;
// 	while (++x < WIN_WIDTH)
// 	{
// 		y = WIN_HEIGHT / 2 - 1;
// 		while (++y < WIN_HEIGHT)
//             put_pixel_2img(window()->image, x, y, color1);
// 			/* mlx_pixel_put(window()->mlx, window()->window_ptr, x, y, 
// 			texture()->c[3]); */
// 	}
// 	x = -1;
// 	while (++x < WIN_WIDTH)
// 	{
// 		y = -1;
// 		while (++y < WIN_HEIGHT / 2)
//             put_pixel_2img(window()->image, x, y, color2);
// 			/* mlx_pixel_put(window()->mlx, window()->window_ptr, x, y, 
// 			texture()->c[3]); */
// 	}
//mlx_put_image_to_window(window()->mlx, window()->window_ptr,
//window()->image->img_ptr, 0, 0);
// 	raycasting();
// }

void	render(int column, float distance)
{
	int		wall_height;
	int		wall_top;
	int		pos;

	if (ray()->intersect_x == 0 && ray()->intersect_y == 0)
		return ;
	wall_height = (int)(map_global()->y_max / distance);
	wall_top = (map_global()->y_max - wall_height) / 2;
	pos = calculate_texture_index();
	if (pos == -1)
		return ;
	mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
	window()->img[pos], column, wall_top);
}

//wall_bottom = wall_top + wall_height;