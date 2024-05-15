/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:47:16 by matilde           #+#    #+#             */
/*   Updated: 2024/03/12 17:38:18 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// keys
# define ESC 0xff1b
# define A 0x61
# define W 0x77
# define D 0x64
# define S 0x73
# define LAK 0xff51
# define RAK 0xff53

# include "libft/inc/libft.h"
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5Z
# endif

# define PI 3.14159265358979323846
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1050
# define TEX_SIZE 64
# define M_PI 3.14159265358979323846
# define MOVE_SPEED 0.08
# define ROTA_SPEED 0.05

#define MALLOC_ERR "Error allocating in _FILE_"
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_player
{
	char			dirc;
	double 			pos_x;
	double 			pos_y;
	double 			dir_x;
	double 			dir_y;
	double          plane_x;
	double		    plane_y;
	bool			has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
}					t_player;

// the map is here in this linked list (line)
typedef struct s_map
{
	int				len;
	int				i;
	char			*line;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

typedef struct s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_img2
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
	int				width;
	int				height;
}					t_img2;

// has the max lengths of the map and the position of the camera (player)
typedef struct s_map_global
{
	int				px;
	int				py;
	int				fd;
	char			*path;
	char			*gnl;
	int				x_max;
	int				y_max;
	char			orientation;
}					t_map_global;

// has the window and the images
typedef struct s_window
{
	char			*win;
	t_img			*image;
	char			*mlx;
}					t_window;

// in here are the paths and code numbers for the colors and textures
typedef struct s_texture
{
	void			*no;
	void			*so;
	void			*ea;
	void			*we;
	int				*f;
	int				*c;
	unsigned long	h_floor;
	unsigned long	h_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}					t_texture;

// has the angle, distance and ray coordinates of the intersections
typedef struct s_ray
{
	double			camera_x;
	int				map_x;
	int				map_y;
	int				steps_x;
	int				steps_y;
	double 			dir_x;
	double 			dir_y;
	double			side_len_x;
	double			side_len_y;
	double 			delta_len_x;
	double 			delta_len_y;
	double			wall_len;
	double			wall_x;
	int				side;
	int				line_height;
	int				render_start;
	int				render_end;
	int				hit_wall;
}					t_ray;

typedef struct s_c3d
{
	void			*mlx;
	void			*win;
    t_ray           r;
    t_texture       t;
    t_player        p;
    t_map_global    mg;
    t_map           m;
    double           framerate;
    double          move_speed;
    double          rota_speed;
    int             height;
    int             width;
	t_img			image;
	t_img2			tex_img[4];
    int				tex[4][TEX_SIZE * TEX_SIZE];
}					t_c3d;

// Raycast functions//
void				raycasting(void);
void                render_floor(void);
void                render_ceiling(void);
void				launch_ray(int x);
void				do_dda(void);
void				step_side_len(void);
void				perp_render(void);
void				render_textures(int x);
// Raycast functions//

t_c3d				*c3d(void);
char				map_iter(int x, int y);
void				put_pixel_2img(int x, int y, int color);
int					init_tex(void);
t_player			*player(void);
t_map				*map(void);
t_texture			*tex(void);
void				printin(int i);
t_window			*window(void);
void init_start(int x, int y);
void				parsing(char *path);
void				check_wall(int i);
int					key_handler(int key);
int					free_all(int i);
void				error(char *str);
char				*get_next_line(int fd, int i, int e, char *line);
void				check_map(char *path, int i);
void				init_map(int i, int j, char *line, t_map *map1);
char				*rm_nl(char *str);
void				check_chars(int i, int pos);
void				parse_north(char **trim, char **trim1, int i, int *no);
void				parse_south(char **trim, char **trim1, int i, int *no);
void				parse_west(char **trim, char **trim1, int i, int *no);
void				parse_east(char **trim, char **trim1, int i, int *no);
void				new_window(void);
int					skipspace(char *str);
int					aux_map(t_map *map1, int max);
void				check_walls(void);
void				check_walls2(t_map *map1);
void				first_last(int i, t_map *map1);
void				look_right(void);
void				look_left(void);
void				parse_rgb(char **trim, char **trim1, int *c, int *f);
void				rgb_c(int i, char **split, int e);
void				rgb_f(int j, char **split, int e);
void				parse_rgb2(char **trim, char **trim1, char ***split, int i);
void				prep_texture(int no, int i, char *trim, char *trim1);
void				freeing(void);
void				img_func(void);
void				textur_mapping(double x, double y);
void				raycasting(void);
t_ray				*ray(void);
char				*rm_space(char *str);
void				free_trim(char **trim, char **trim1, char *message,
						char ***split);
void				set_player_start(char x);
void				open_textures(char *path);

#endif
