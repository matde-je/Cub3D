/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:25:37 by matilde           #+#    #+#             */
/*   Updated: 2024/02/16 16:30:29 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	new_window(void)
{
	window()->mlx_ptr = mlx_init();
	if (!window()->mlx_ptr)
		free_all(0);
	(window()->window_ptr) = mlx_new_window(window()->mlx_ptr, \
	(map_global()->x_max * 64), (map_global()->y_max * 64), "have fun");
	if (!window()->window_ptr)
		free_all(0);
	//img_func();
}

// void	img_func(void)
// {
// 	int	h;
// 	int	w;

// 	h = 64;
// 	w = 64;
// 	(window()->img['N']) = mlx_xpm_file_to_image(window()->mlx_ptr, 
// 	"xpm_files/porco.xpm", &w, &h);
// 	(window()->img['1']) = mlx_xpm_file_to_image(window()->mlx_ptr, 
// 	"xpm_files/arvore.xpm", &w, &h);
// 	(window()->img['0']) = mlx_xpm_file_to_image(window()->mlx_ptr, 
// 	"xpm_files/branco.xpm", &w, &h);
// 	window_img();
// }

// void	window_img(void)
// {
// 	int	count;
// 	int	count2;
// 	int	pos;

// 	count = -1;
// 	while (++count < map_global->size_y)
// 	{
// 		count2 = -1;
// 		while (++count2 < map_global->size_x)
// 		{
// 			pos = map_global->matrix[count][count2];
// 			if (window()->img[pos])
// 			{
// 				mlx_put_image_to_window(window()->mlx_ptr, 
// 				window()->window_ptr, window()->img[pos], 
// 				count2 * 64, count * 64);
// 			}
// 		}
// 	}
// }
