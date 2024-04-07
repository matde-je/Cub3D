/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:24:41 by matilde           #+#    #+#             */
/*   Updated: 2024/04/07 14:51:26 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	raycasting(void)
// {
// 	t_map	*map1;
// 	int		j;

// 	map1 = map();
// 	while (map1)
// 	{
// 		j = -1;
// 		while (++j < map1->len)
// 		{
// 			if (map1->line[j] == '1')
// 			{
// 				ray()->x = j;
// 				ray()->y = map1->i;
// 				ray_dist_angle(map_global()->px, j, map_global()->py, ray()->y);
// 				if (ray()->angle <= 0.1 || (ray()->y != 0 && ray()->y != \
// 				map_global()->y_max && (ray()->x == skipspace(map1->line) || \
// 				ray()->x == map_global()->x_max)))
// 					render_cube2((map_global()->x_max * 32) / ray()->distance, \
// 					player_angle(), calculate_texture_index());
// 				render_cube();
// 			}
// 		}
// 		map1 = map1->next;
// 	}
// }

// //calculating ray distance and angle
// void	ray_dist_angle(int x1, int x2, int y1, int y2)
// {
// 	(ray()->distance) = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
// 	(ray()->angle) = atan2(sqrt(pow(ray()->y - map_global()->py, 2)), \
// 	sqrt(pow(ray()->x - map_global()->px, 2)));
// }

