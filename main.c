/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/02/15 15:06:13 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error("Error in number of arguments");
	check_name(argv[1]);
	new_window();
	mlx_key_hook(window()->window_ptr, key_handler, NULL);
	mlx_hook(window()->window_ptr, 17, 131072, &free_all, NULL);
	if (window()->window_ptr)
		mlx_loop(window()->mlx_ptr);
	free_all(0);
	return (0);
}

void	error(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	free_all(1);
}

int	free_all(int i)
{
	int	count;

	count = -1;
	while (++count < map()->size_y)
		free(map()->matrix[count]);
	free(map()->matrix);
	if (window()->img['N'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['N']);
	if (window()->img['0'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['0']);
	if (window()->img['1'])
		mlx_destroy_image(window()->mlx_ptr, window()->img['0']);
	if (window()->window_ptr)
		mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
	if (window()->mlx_ptr)
	{
		mlx_destroy_display(window()->mlx_ptr);
		free(window()->mlx_ptr);
	}
	if (i == 0)
		exit(0);
	if (i == 1)
		exit(1);
	return (0);
}

t_map	*map(void)
{
	static t_map	var;

	return (&var);
}

t_window	*window(void)
{
	static t_window		var;

	return (&var);
}
