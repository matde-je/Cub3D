#include "../../cub3d.h"

void render_textures(int x)
{
    int y;
    double step;

    step = 0;
    cub3()->ray.wall_x = 0;
    if (cub3()->ray.side == 0)
        cub3()->ray.wall_x = map_global()->pos_y + cub3()->ray.perp_wall_len *\
                          cub3()->ray.ray_dir.x;
    else
        cub3()->ray.wall_x = map_global()->pos_x + cub3()->ray.perp_wall_len *\
                          cub3()->ray.ray_dir.x;
    cub3()->ray.wall_x = floor(cub3()->ray.wall_x) ;
    cub3()->ray.tex_x = (int) (cub3()->ray.wall_x * (double)TEX_SIZE);
    if (cub3()->ray.side == 0 && cub3()->ray.ray_dir.x > 0)
        cub3()->ray.tex_x = TEX_SIZE - cub3()->ray.tex_x - 1;
    if (cub3()->ray.side == 0 && cub3()->ray.ray_dir.y < 0)
        cub3()->ray.tex_x = TEX_SIZE - cub3()->ray.tex_x - 1;
    //vertical texture stripe
    step = 1.0 * TEX_SIZE / cub3()->ray.line_height;
    cub3()->ray.texture_pos = (cub3()->ray.render_start - \
            WIN_HEIGHT / 2 + cub3()->ray.line_height / 2 ) * step;
    cub3()->ray.y = cub3()->ray.render_start;
    while(y < cub3()->ray.render_end)
    {
        cub3()->ray.tex_y = (int) cub3()->ray.texture_pos & (TEX_SIZE - 1);
        cub3()->ray.texture_pos += step;
    }
}
