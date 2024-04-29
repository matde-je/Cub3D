#include "../cub3d.h"

void mk_text_buffer(void)
{
    int i;

    tex()->tex_pix = ft_calloc(WIN_HEIGHT + 1, sizeof(tex()->tex_pix));
        if (!tex()->tex_pix)
            ft_putstr_fd("tex_pix alloc fail\n", 2);
    i = -1;
    while(++i < WIN_HEIGHT)
    {
        tex()->tex_pix[i] = ft_calloc(WIN_HEIGHT, sizeof(tex()->tex_pix));
        if (!tex()->tex_pix[i])
            ft_putstr_fd("tex_pix alloc fail\n", 2);
    }
}

void fill_tex_arr(int i)
{
    t_point it;
    t_img *tmp;

    it = (t_point){-1, -1};
    while(++y )
}
void init_textures(void)
{
}
xp
