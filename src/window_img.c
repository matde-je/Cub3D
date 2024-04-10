/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:37 by matilde           #+#    #+#             */
/*   Updated: 2024/03/12 17:47:25 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdlib.h>

// display the window
void	new_window(void)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (img == NULL)
	{
		ft_putstr_fd("Fail on img alloc", 2);
		exit(1);
	}
	window()->mlx = mlx_init();
	if (!window()->mlx)
		free_all(0);
	(window()->window_ptr) = mlx_new_window(window()->mlx, WIN_WIDTH,
			WIN_HEIGHT, "have fun");
	if (!window()->window_ptr)
		free_all(0);
	img->img_ptr = mlx_new_image(window()->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img_ptr)
		exit(1);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size),
			&(img->endian));
	window()->image = img;
    raycasting();
	put_cf_colors();
}

// loads the textures of the walls to img['orientation']
// void	img_func(void)
// {
// 		int	w;

// 	/* 	int	h;
// 		h = 32;
// 		w = 32;
// 		(window()->img['N']) = mlx_xpm_file_to_image(window()->mlx, \
// 		"./textures/HEDGE.xpm", &w, &h);
// 		(window()->img['S']) = mlx_xpm_file_to_image(window()->mlx, \
// 		"./textures/SLIME.xpm", &w, &h);
// 		(window()->img['W']) = mlx_xpm_file_to_image(window()->mlx, \
// 		"./textures/SLUDGE.xpm", &w, &h);
// 		(window()->img['E']) = mlx_xpm_file_to_image(window()->mlx, \
// 		"./textures/WARN.xpm", &w, &h); */
// }
// puts in window the ceiling and floor colors, pixel by pixel (slow proccess)
void	put_cf_colors(void)
{
	int	y;
	int	x;
	int	color1;
	int	color2;

	color1 = texture()->c[0] << 16 | texture()->c[1] << 8 | texture()->c[2];
	color2 = texture()->f[0] << 16 | texture()->f[1] << 8 | texture()->f[2];
	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2 - 1;
		while (++y < WIN_HEIGHT)
			put_pixel_2img(window()->image, x, y, color1);
	}
	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
			put_pixel_2img(window()->image, x, y, color2);
	}
	mlx_put_image_to_window(window()->mlx, window()->window_ptr,
		window()->image->img_ptr, 0, 0);
}

// algorithm
// void	raycasting(void)
// {
// 	float	step;
// 	int		max;

// 	step = 0.1;
// 	max = 100;
// 	//printf("map %i\n", map_global()->pos_x);
// 	ray()->x = map_global()->pos_x;
// 	ray()->y = map_global()->pos_y;
// 	while (1)
// 	{
// 		if (sqrt(pow(ray()->x - map_global()->pos_x, 2) +
// 			pow(ray()->y - map_global()->pos_y, 2)) < 0.1)
// 			break ;
// 		if (sqrt(pow(ray()->x - map_global()->pos_x, 2) +
// 			pow(ray()->y - map_global()->pos_y, 2)) > max)
// 			return ;
// 		ray()->x += step;
// 		ray()->y += step;
// 	}
// 	textur_mapping();
// }
