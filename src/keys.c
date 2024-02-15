/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:55 by matilde           #+#    #+#             */
/*   Updated: 2024/02/15 15:22:40 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'N')
			{
				if (map()->matrix[count -1][count2] == '1')
					return ;
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				map()->matrix[count - 1][count2] = 'N';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['N'], \
				count2 * 64, (count - 1) * 64);
				return ;
			}
		}
	}
}

void	move_down(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'N')
			{
				if (map()->matrix[count +1][count2] == '1')
					return ;
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				map()->matrix[count + 1][count2] = 'N';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['N'], \
				count2 * 64, (count + 1) * 64);
				return ;
			}
		}
	}
}

void	move_left(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'N')
			{
				if (map()->matrix[count][count2 -1] == '1')
					return ;
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				map()->matrix[count][count2 - 1] = 'N';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['N'], \
				(count2 - 1) * 64, count * 64);
				return ;
			}
		}
	}
}

void	move_right(int count, int count2)
{
	while (++count < map()->size_y)
	{
		count2 = -1;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'N')
			{
				if (map()->matrix[count][count2 +1] == '1')
					return ;
				map()->matrix[count][count2] = '0';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['0'], \
				count2 * 64, count * 64);
				map()->matrix[count][count2 + 1] = 'N';
				mlx_put_image_to_window(window()->mlx_ptr, \
				window()->window_ptr, window()->img['N'], \
				(count2 + 1) * 64, count * 64);
				return ;
			}
		}
	}
}

int	key_handler(int key)
{
	int	count;
	int	count2;

	count = -1;
	count2 = -1;
	if (key == ESC)
		free_all(0);
	else if (key == W)
		move_up(count, count2);
	else if (key == A)
		move_left(count, count2);
	else if (key == D)
		move_right(count, count2);
	else if (key == S)
		move_down(count, count2);
	return (0);
}
