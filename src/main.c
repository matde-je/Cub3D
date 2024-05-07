/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+		+#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/03/20 11:09:27 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


t_c3d *cub3(void)
{
    static t_c3d var;

    var.height = WIN_HEIGHT;
    var.width = WIN_WIDTH;
    return (&var);
}

int start_all(void)
{
    render_floor();
    render_ceiling();
    raycasting();
    cub3()->framerate = 16 /1000.0;
    cub3()->move_speed = cub3()->framerate * 5.0;
    cub3()->rota_speed = cub3()->framerate * 3.0;
    mlx_put_image_to_window(cub3()->mlx, cub3()->win, \
            cub3()->image.img_ptr, 0, 0);
    // mlx_destroy_image(cub3()->mlx, cub3()->image.img_ptr);
    return (0);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
		error("Number of arguments");
    cub3()->mlx = mlx_init();
    cub3()->image.img_ptr = mlx_new_image(cub3()->mlx, WIN_WIDTH, WIN_HEIGHT);
    cub3()->win = mlx_new_window(cub3()->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    cub3()->image.addr = mlx_get_data_addr(cub3()->image.img_ptr, 
            &cub3()->image.bpp, &cub3()->image.size, &cub3()->image.endian);
	parsing(argv[1]);
    mlx_loop_hook(cub3()->mlx, start_all, NULL);
	mlx_key_hook(cub3()->win, key_handler, NULL);
	mlx_hook(cub3()->win, 17, 1L << 17, &free_all, NULL);
	if (cub3()->win)
        mlx_loop(cub3()->mlx);
	free_all(0);
	return (0);
}

void	error(char *str)
{
	int	i;

	i = -1;
	write(2, "Error\n", 6);
	while (str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 1);
	free_all(1);
	exit(1);
}

