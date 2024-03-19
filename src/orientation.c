/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:07:05 by matilde           #+#    #+#             */
/*   Updated: 2024/03/19 16:08:32 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_angle(void)
{
	t_map	*map1;
	int		player_angle;

	map1 = map();
	while (map1 && map1->i != map_global()->py)
		map1 = map1->next;
	if (map1->line[map_global()->px] == 'N')
		player_angle = 0;
	else if (map1->line[map_global()->px] == 'S')
		player_angle = 180;
	else if (map1->line[map_global()->px] == 'E')
		player_angle = 90;
	else if (map1->line[map_global()->px] == 'W')
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
		if (ray()->x < map_global()->px)
			pos = 'E';
		else if (ray()->x > map_global()->px)
			pos = 'W';
	}
	else if (player == 180)
	{
		pos = 'S';
		if (ray()->x < map_global()->px)
			pos = 'E';
		else if (ray()->x > map_global()->px)
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
		*pos = 'O';
		if (ray()->y > map_global()->py)
			*pos = 'N';
		else if (ray()->y < map_global()->py)
			*pos = 'S';
	}
	else if (player == 270)
	{
		*pos = 'E';
		if (ray()->y > map_global()->py)
			*pos = 'N';
		else if (ray()->y < map_global()->py)
			*pos = 'S';
	}
}

void	render_cube(void)
{
	int	size;
	int	pos;
	int	player;

	size = (map_global()->x_max * 32) / ray()->distance;
	player = player_angle();
	pos = calculate_texture_index();
	if (pos == -1)
		return ;
	if (player == 0 && ray()->y < map_global()->py)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img['N'], ray()->x - size / 2, ray()->y - size / 2);
	else if (player == 180 && ray()->y > map_global()->py)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img['S'], ray()->x - size / 2, \
		((ray()->y - size) / 2) + size);
	else if (player == 270 && ray()->x < map_global()->px)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img['E'], ray()->x - size / 2, ray()->y - size / 2);
	else if (player == 90 && ray()->x > map_global()->px)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img['W'], ray()->x + size / 2, ray()->y - size / 2);
	render_cube2(size, player, pos);
}

void	render_cube2(int size, int player, int pos)
{
	t_map	*map1;
	int		i;

	i = 0;
	map1 = map();
	while (map1->i != ray()->y)
		map1 = map1->next;
	while (map1->line[i] == ' ')
		i++;
	if (ray()->y == 0 || ray()->y == map_global()->y_max || \
		map1->len - 1 == ray()->x || i == ray()->x)
		return ;
	if (pos == 'W' && player != 90)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img[pos], ray()->x - size / 2, ray()->y - size / 2);
	else if (pos == 'E' && player != 270)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img[pos], ray()->x + size / 2, ray()->y - size / 2);
	else if (pos == 'N' && player != 0)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img[pos], ray()->x - size / 2, ray()->y - size / 2);
	else if (pos == 'S' && player != 180)
		mlx_put_image_to_window(window()->mlx, window()->win, \
		window()->img[pos], \
		ray()->x - size / 2, ((ray()->y - size) / 2) + size);
}

// int front_vertices[4][2] = {
//{ray()->x - size / 2, ray()->y - size / 2},
//Front bottom left
// int left_vertices[4][2] = {
//{ray()->x - size / 2, ray()->y - size / 2},
//Left bottom front
// int right_vertices[4][2] = {
//{ray()->x + size / 2, ray()->y - size / 2},
//Right bottom front