/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:42:55 by matilde           #+#    #+#             */
/*   Updated: 2024/02/16 16:30:13 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(int count, int count2)
{
	while (++count < map(0)->i)
	{
		count2 = -1;
		while (++count2 < map(0)->len)
		{
			if (map(0)->line[count] == 'N')
			{
				if (map(0)->line[count -1] == '1')
					return ;
				map(0)->line[count] = '0';
				//mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['0'], 
				// count2 * 64, count * 64);
				map(0)->line[count - 1] = 'N';
				//mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['N'], 
				// count2 * 64, (count - 1) * 64);
				return ;
			}
		}
	}
}

void	move_down(int count, int count2)
{
	while (++count < map(0)->i)
	{
		count2 = -1;
		while (++count2 < map(0)->len)
		{
			if (map(0)->line[count] == 'N')
			{
				if (map(0)->line[count +1] == '1')
					return ;
				map(0)->line[count] = '0';
				// mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['0'], 
				// count2 * 64, count * 64);
				map(0)->line[count + 1] = 'N';
				// mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['N'], 
				// count2 * 64, (count + 1) * 64);
				return ;
			}
		}
	}
}

void	move_left(int count, int count2)
{
	while (++count < map(0)->i)
	{
		count2 = -1;
		while (++count2 < map(0)->len)
		{
			if (map(0)->line[count] == 'N')
			{
				if (map(0)->line[count] == '1')
					return ;
				map(0)->line[count] = '0';
				// mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['0'], 
				// count2 * 64, count * 64);
				map(0)->line[count] = 'N';
				// mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['N'], 
				// (count2 - 1) * 64, count * 64);
				return ;
			}
		}
	}
}

void	move_right(int count, int count2)
{
	while (++count < map(0)->i)
	{
		count2 = -1;
		while (++count2 < map(0)->len)
		{
			if (map(0)->line[count] == 'N')
			{
				if (map(0)->line[count] == '1')
					return ;
				map(0)->line[count] = '0';
				// mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['0'], 
				// count2 * 64, count * 64);
				map(0)->line[count] = 'N';
				// mlx_put_image_to_window(window()->mlx_ptr, 
				// window()->window_ptr, window()->img['N'], 
				// (count2 + 1) * 64, count * 64);
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
