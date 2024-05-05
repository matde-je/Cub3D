#include "../cub3d.h"

static void xpm_to_pixel(char *xpm, t_img2 *i, int tex_index)
{
    int x;
    int y;

    i->img_ptr = mlx_xpm_file_to_image(cub3()->mlx, xpm, &i->width, 
            &i->height);
    i->addr = mlx_get_data_addr(cub3()->mlx, &i->bpp, &i->size, &i->endian);
    y = -1;
    while(++y < TEX_SIZE)
    {
        x = -1;
        while(++x < TEX_SIZE)
            cub3()->tex[tex_index][y * TEX_SIZE + x] = i->addr[y * TEX_SIZE + x];
    } 
    mlx_destroy_image(cub3()->mlx, i->img_ptr);
}

int init_tex(void)
{
    xpm_to_pixel(tex()->ea, &cub3()->tex_img[EAST], EAST);
    xpm_to_pixel(tex()->no, &cub3()->tex_img[NORTH], NORTH);
    xpm_to_pixel(tex()->so, &cub3()->tex_img[SOUTH], SOUTH);
    xpm_to_pixel(tex()->we, &cub3()->tex_img[WEST], WEST);
    return (0);
}


