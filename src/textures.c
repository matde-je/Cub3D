#include "../cub3d.h"

static void xpm_to_pixel(char *xpm, t_img2 *i, int tex_index)
{
    int x;
    int y;

    i->ptr = mlx_xpm_file_to_image(c3d()->mlx, xpm, &i->width, 
            &i->height);
    i->addr = mlx_get_data_addr(c3d()->mlx, &i->bpp, &i->size, &i->endian);
    y = -1;
    while(++y < i->height)
    {
        x = -1;
        while(++x < i->height)
        {
            c3d()->tex[tex_index][i->height * y + x] =  \
                i->addr[i->height * y + x];
        }
    } 
    if (!i->addr)
        error("Error_FILE_ _LINE_");
    mlx_destroy_image(c3d()->mlx, i->ptr);
}

int init_tex(void)
{
    xpm_to_pixel(c3d()->t.ea, &c3d()->tex_img[EAST], EAST);
    xpm_to_pixel(c3d()->t.no, &c3d()->tex_img[NORTH], NORTH);
    xpm_to_pixel(c3d()->t.so, &c3d()->tex_img[SOUTH], SOUTH);
    xpm_to_pixel(c3d()->t.we, &c3d()->tex_img[WEST], WEST);
    return (0);
}


