/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:07:05 by matilde           #+#    #+#             */
/*   Updated: 2024/03/18 12:04:06 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_angle(void)
{
	t_map	*map1;
	int		player_angle;

	map1 = map();
	while (map1 && map1->i != map_global()->pos_y)
		map1 = map1->next;
	if (map1->line[map_global()->pos_x] == 'N')
		player_angle = 0;
	else if (map1->line[map_global()->pos_x] == 'S')
		player_angle = 180;
	else if (map1->line[map_global()->pos_x] == 'E')
		player_angle = 90;
	else if (map1->line[map_global()->pos_x] == 'W')
		player_angle = 270;
	return (player_angle);
}

int	calculate_texture_index(void)
{
	int	pos;
	int	player;

	pos = -1;
	player = player_angle();
	if (player == 0)
	{
		pos = 'N';
		if (ray()->intersect_x < map_global()->pos_x)
			pos = 'W';
		else if (ray()->intersect_x > map_global()->pos_x)
			pos = 'E';
	}
	else if (player == 180)
	{
		pos = 'S';
		if (ray()->intersect_x < map_global()->pos_x)
			pos = 'E';
		else if (ray()->intersect_x > map_global()->pos_x)
			pos = 'W';
	}
	else
		texture_index(player, &pos);
	return (pos);
}

void	texture_index(int player, int *pos)
{
	if (player == 90)
	{
		*pos = 'E';
		if (ray()->intersect_y > map_global()->pos_y)
			*pos = 'N';
		else if (ray()->intersect_y < map_global()->pos_y)
			*pos = 'S';
	}
	else if (player == 270)
	{
		*pos = 'W';
		if (ray()->intersect_y > map_global()->pos_y)
			*pos = 'N';
		else if (ray()->intersect_y < map_global()->pos_y)
			*pos = 'S';
	}
}

// int front_vertices[4][2] = {
//{ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2},
//Front bottom left
// int left_vertices[4][2] = {
//{ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2},
//Left bottom front
// int right_vertices[4][2] = {
//{ray()->intersect_x + cube_size / 2, ray()->intersect_y - cube_size / 2},
//Right bottom front
void	render_cube(float distance)
{
	int	cube_size;
	int	pos;
	int	player;

	cube_size = (map_global()->x_max * 32) / distance;
	player = player_angle();
	pos = calculate_texture_index();
	if (pos == -1)
		return ;
	if (player == 'N')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[player], \
		ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2);
	else if (player == 'S')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[player], ray()->intersect_x - cube_size / 2, \
		((ray()->intersect_y - cube_size) / 2) + cube_size);
	else if (player == 'W')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[player], ray()->intersect_x - cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	else if (player == 'E')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[player], ray()->intersect_x + cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	if (pos == 'W')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], ray()->intersect_x - cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	else if (pos == 'E')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], ray()->intersect_x + cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	else if (pos == 'N' && player != 'N')
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], \
		ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2);
}
// mlx_put_image_to_window(window()->mlx, window()->window_ptr, 
// window()->img[player], ray()->intersect_x - cube_size / 2, );
// if (pos != player)
// 	mlx_put_image_to_window(window()->mlx, window()->window_ptr, 
// 	window()->img[pos], ray()->intersect_x - cube_size / 2, );
