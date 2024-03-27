/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/03/13 21:11:57 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/inc/libft.h"

char map_iter(int x, int y)
{
    int i;
    int j;
    t_map *it;

    i = -1;
    j = -1;
    it = map();
    while (++i <= x)
    {
        while (++j <= y && it->line[j] != '\0')
            return (it->line[j]);
        it = it->next;
    }
    return (' ');
}

t_c3d *cub3(void)
{
    static t_c3d cub3;

    return (&cub3);
}

int err_out(char *msg)
{
    ft_putstr_fd(msg, 1);
    exit(1);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
		error("Number of arguments");
	parsing(argv[1]);
    // init();
	new_window();
	mlx_key_hook(window()->window_ptr, key_handler, NULL);
	mlx_hook(window()->window_ptr, 17, 131072, &free_all, NULL);
	if (window()->window_ptr)
		mlx_loop(window()->mlx);
	free_all(0);
	return (0);
}
