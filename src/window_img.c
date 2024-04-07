/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:37 by matilde           #+#    #+#             */
/*   Updated: 2024/04/07 17:23:00 by matde-je         ###   ########.fr       */
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
	(window()->win) = mlx_new_window(window()->mlx, WIN_WIDTH, WIN_HEIGHT,
			"have fun");
	if (!window()->win)
		free_all(0);
	img->img_ptr = mlx_new_image(window()->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img_ptr)
		exit(1);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size),
			&(img->endian));
	window()->image = img;
	put_cf_colors();
}

void	put_cf_colors(void)
{
	int	y;
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2 - 1;
		while (++y < WIN_HEIGHT)
			put_pixel_2img(window()->image, x, y, texture()->c[3]);
	}
	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
			put_pixel_2img(window()->image, x, y, texture()->f[3]);
	}
	mlx_put_image_to_window(window()->mlx, window()->win,
		window()->image->img_ptr, 0, 0);
}

// loads the textures of the walls to img['orientation']
// void	img_func(void)
// {
// 		int	w;
// 	/* 	int	h;
// 		h = 32;
// 		w = 32;
// 		(window()->img['N']) = mlx_xpm_file_to_image(window()->mlx,
// 		"./textures/HEDGE.xpm", &w, &h);
// 		(window()->img['S']) = mlx_xpm_file_to_image(window()->mlx,
// 		"./textures/SLIME.xpm", &w, &h);
// 		(window()->img['W']) = mlx_xpm_file_to_image(window()->mlx,
// 		"./textures/SLUDGE.xpm", &w, &h);
// 		(window()->img['E']) = mlx_xpm_file_to_image(window()->mlx,
// 		"./textures/WARN.xpm", &w, &h); */
// }
// puts in window the ceiling and floor colors, pixel by pixel (slow proccess)
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