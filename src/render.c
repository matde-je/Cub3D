#include "../cub3d.h"

void	put_pixel_2img(int x, int y, int color)
{
    if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
        return ;
    *(int *)&c3d()->image.addr[(y * c3d()->image.size) + \
    (x * (c3d()->image.bpp / 8))] = color;
}

void render_floor(void)
{
    int	y;
    int	x;

    x = -1;
    while (++x < WIN_WIDTH)
    {
        y = WIN_HEIGHT / 2 - 1;
        while (++y < WIN_HEIGHT)
            put_pixel_2img(x, y, c3d()->t.f[3]);
    }
}

void render_ceiling(void)
{
	int	y;
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT / 2)
			put_pixel_2img(x, y, c3d()->t.c[3]);
	}
}

void raycasting(void)
{

    int x;
    x = -1;
    while(++x < WIN_WIDTH)
    {
        launch_ray(x);
        step_side_len();
        do_dda();
        perp_render();
        render_textures(x);
    }
}
