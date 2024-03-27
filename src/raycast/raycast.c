#include "../../cub3d.h"

void launch_ray(int x)
{
    cub3()->ray.camera_x = 2 * x / (double) WIN_WIDTH - 1;
    cub3()->ray.ray_dir.x = cub3()->ray.dir.x + \
                            cub3()->ray.plane.x * cub3()->ray.camera_x;
    cub3()->ray.ray_dir.y = cub3()->ray.dir.y + \
                            cub3()->ray.plane.y * cub3()->ray.camera_x;
    cub3()->ray.map_x = (int) cub3()->ray.pos.x;
    cub3()->ray.map_y = (int) cub3()->ray.pos.y;
    cub3()->ray.hit_wall = 0;
    if (cub3()->ray.ray_dir.x == 0)
        cub3()->ray.delta_len.x = 1e30;
    else 
        cub3()->ray.delta_len.x = fabs(1 / cub3()->ray.ray_dir.x); 
    if (cub3()->ray.ray_dir.y == 0)
        cub3()->ray.delta_len.y = 1e30;
    else 
        cub3()->ray.delta_len.y = fabs(1 / cub3()->ray.ray_dir.y);
}

void dda(void)
{
    while (cub3()->ray.hit_wall == 0)
    {
        if (cub3()->ray.side_len.x < 
                cub3()->ray.side_len.y)
        {
            cub3()->ray.side_len.x += cub3()->ray.delta_len.x;
            cub3()->ray.map_x += cub3()->ray.steps_x;
            cub3()->ray.side = 0;
        }
        else
        { 
            cub3()->ray.side_len.y += cub3()->ray.delta_len.y;
            cub3()->ray.map_y += cub3()->ray.steps_y;
            cub3()->ray.side = 0;
        }
        if(map_iter(cub3()->ray.map_x,
            cub3()->ray.map_y) > 0)
            cub3()->ray.hit_wall = 1;
    }
}


void step_side_len_x(void)
{
    if (cub3()->ray.ray_dir.x < 0)
    {
        cub3()->ray.steps_x = -1;
        cub3()->ray.side_len.x = (cub3()->ray.pos.x - cub3()->ray.map_x) \
                                 * cub3()->ray.delta_len.x;
    }
    else
    {
        cub3()->ray.steps_x = 1;
        cub3()->ray.side_len.x = (cub3()->ray.map_x + 1.0 - cub3()->ray.pos.x) \
                                 * cub3()->ray.delta_len.x;
    }
}

void step_side_len_y(void)
{
    if (cub3()->ray.ray_dir.y < 0)
    {
        cub3()->ray.steps_y = -1;
        cub3()->ray.side_len.y = (cub3()->ray.pos.y - cub3()->ray.map_y) \
                                 * cub3()->ray.delta_len.y;
    }
    else
    {
        cub3()->ray.steps_y = 1;
        cub3()->ray.side_len.y = (cub3()->ray.map_y + 1.0 - cub3()->ray.pos.y) \
                                 * cub3()->ray.delta_len.y;
    }
}

void perp_render(void)
{
    if (cub3()->ray.side == 0)
        cub3()->ray.perp_wall_len = cub3()->ray.side_len.x \
                                    - cub3()->ray.delta_len.x;
    else
        cub3()->ray.perp_wall_len = cub3()->ray.side_len.x \
                                    - cub3()->ray.delta_len.x;
    cub3()->ray.line_height = \
                              (int) (WIN_HEIGHT / cub3()->ray.perp_wall_len);
    cub3()->ray.render_start = (-1) * cub3()->ray.line_height / 2 \
                               + WIN_HEIGHT / 2;
    if (cub3()->ray.render_start < 0)
        cub3()->ray.render_start = 0; 
    cub3()->ray.render_end = cub3()->ray.line_height / 2 \
                               + WIN_HEIGHT / 2;
    if (cub3()->ray.render_end >= WIN_HEIGHT)
        cub3()->ray.render_end = WIN_HEIGHT - 1;
}


