#include "../cub3d.h"

static int *xpm_to_pixel(char *xpm)
{
    t_img tmp;
    int *buf;
    int x;
    int y;

    tmp.img_ptr = mlx_xpm_file_to_image(cub3()->mlx, xpm, &cub3()->width, 
            &cub3()->height);
    tmp.addr = mlx_get_data_addr(cub3()->mlx, &tmp.bpp, &tmp.size, &tmp.endian);

    buf = ft_calloc(1, sizeof * buf * TEX_SIZE * TEX_SIZE);
    if (!buf)
        error(MALLOC_ERR);
    y = -1;
    while(++y < TEX_SIZE)
    {
        x = -1;
        while(++x < TEX_SIZE)
            buf[y * TEX_SIZE + x] = tmp.addr[y * TEX_SIZE + x];
    } 
    mlx_destroy_image(cub3()->mlx, tmp.img_ptr);
    return (buf);
}

int init_tex(void)
{
    tex()

}


