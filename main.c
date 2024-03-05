/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/03/05 12:25:05 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error("Number of arguments");
	parsing(argv[1]);
	new_window();
	mlx_key_hook(window()->window_ptr, key_handler, NULL);
	mlx_hook(window()->window_ptr, 17, 131072, &free_all, NULL);
	if (window()->window_ptr)
		mlx_loop(window()->mlx);
	free_all(0);
	return (0);
}
