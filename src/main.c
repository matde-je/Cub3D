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


t_c3d *c3d(void)
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
    mlx_put_image_to_window(c3d()->mlx, c3d()->win, \
            c3d()->image.ptr, 0, 0);
    // mlx_destroy_image(c3d()->mlx, c3d()->image.img_ptr);
    return (0);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
		error("Number of arguments");
    parsing(argv[1]);
    c3d()->mlx = mlx_init();
    c3d()->win = mlx_new_window(c3d()->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    c3d()->image.ptr= mlx_new_image(c3d()->mlx, WIN_WIDTH, WIN_HEIGHT);
    c3d()->image.addr = mlx_get_data_addr(c3d()->image.ptr, 
            &c3d()->image.bpp, &c3d()->image.size, &c3d()->image.endian);
    init_tex();
    mlx_loop_hook(c3d()->mlx, start_all, NULL);
	mlx_key_hook(c3d()->win, key_handler, NULL);
	mlx_hook(c3d()->win, 17, 1L << 17, &free_all, NULL);
	if (c3d()->win)
        mlx_loop(c3d()->mlx);
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

