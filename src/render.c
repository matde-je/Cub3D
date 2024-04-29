#include "../cub3d.h"

void	put_pixel_2img(int x, int y, int color)
{
	if (x < 0 || y < 0)
		return ;
	*(int *)&cub3()->image.addr[(y * cub3()->image.size)
        + (x * (cub3()->image.bpp / 8))] = color;
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
			put_pixel_2img(x, y, tex()->c[3]);
	}
}

void render_ceiling(void)
{

	int	y;
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2;
		while (++y < WIN_HEIGHT)
			put_pixel_2img(x, y, tex()->c[3]);
	}
}
