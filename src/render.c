#include "../cub3d.h"

void	put_pixel_2img(t_img *image, int x, int y, int color)
{
	if (x < 0 || y < 0)
		return ;
	*(int *)&image->addr[(y * image->size) + (x * (image->bpp / 8))] = color;
}
