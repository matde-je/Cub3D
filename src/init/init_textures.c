/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:13:43 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/04/01 23:13:43 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../cub3d.h"

static void render_tex(int i)
{
    int x;
    int y;

    y = -1;
    while (++y < cub3()->tex[i].height)
    {
        x = -1;
        while (++x < cub3()->tex[i].width)
        {
            cub3()->tex_arr[i][cub3()->tex[i].height * y + x] = \
                 (cub3()->tex[i].addr[cub3()->tex[i].height * y + x]);
        }
    }
}

int init_tex(void)
{
    int i;
    char *tmp;
    int *addr;

    i = -1;
    while (++i < 4)
    {
        tmp = mlx_xpm_file_to_image(cub3()->mlx, cub3()->xpm[i], \
                &(cub3()->tex[i].width), &(cub3()->tex[i].height));
        cub3()->tex[i].img_ptr = tmp;
        if (!cub3()->tex[i].img_ptr)
            return (1);
        addr = (int *)mlx_get_data_addr(cub3()->tex[i].img_ptr, \
                &cub3()->tex[i].bpp, &cub3()->tex[i].size,  \
                &cub3()->tex[i].endian);
        cub3()->tex[i].addr = addr;
        if (!cub3()->tex[i].addr)
            return (1);
        render_tex(i);
        mlx_destroy_image(cub3()->mlx, cub3()->tex[i].img_ptr);
    }
    return (0);
}
