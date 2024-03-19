/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:47:16 by matilde           #+#    #+#             */
/*   Updated: 2024/03/19 16:33:57 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//keys
# define ESC 0xff1b
# define A 0x61
# define W 0x77
# define D 0x64
# define S 0x73
# define LAK 0xff51
# define RAK 0xff53

# include "libft/inc/libft.h"
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define PI 3.14159265358979323846

//the map is here in this linked list (line)
typedef struct s_map
{
	int				len;
	int				i;
	char			*line;
	struct s_map	*prev;
	struct s_map	*next;
}				t_map;

//has the max lengths of the map and the position of the camera (player)
typedef struct s_map_global
{
	int				px;
	int				py;
	int				fd;
	char			*path;
	char			*gnl;
	int				x_max;
	int				y_max;
}				t_map_global;

//has the window and the images
typedef struct s_window
{
	char	*win;
	void	*img[200];
	char	*mlx;
}				t_window;

//in here are the paths and code numbers for the colors and textures
typedef struct s_texture
{
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		*f;
	int		*c;
}	t_texture;

//has the angle, distance and ray coordinates of the intersections
typedef struct s_ray
{
	int		x;
	int		y;
	float	angle;
	float	distance;
}				t_ray;

t_map			*map(void);
t_texture		*texture(void);
void			printin(int i);
t_window		*window(void);
void			parsing(char *path);
void			check_wall(int i);
int				key_handler(int key);
int				free_all(int i);
void			error(char	*str);
char			*get_next_line(int fd);
char			*ft_strjoin1(char *linha, char *buffer);
void			check_map(char *path);
void			init_map(void);
void			check_map(char *path);
char			*rm_nl(char	*str);
void			check_chars(int i);
void			new_window(void);
t_map_global	*map_global(void);
int				aux_map(t_map *map1, int max);
void			check_walls(void);
void			check_walls2(t_map *map1);
void			look_right(void);
void			look_left(void);
void			parse_rgb(char **trim, char **trim1);
void			rgb_c(int i, char **split, int e);
void			rgb_f(int j, char **split, int e);
int				parse_rgb2(char **trim, char **trim1, char ***split);
void			parse_textures(char **trim, char **trim1, char **gnl);
void			prep_texture(char *path);
void			count_texture(char **trim, char **trim1);
void			freeing(void);
void			img_func(void);
void			put_cf_colors(void);
int				calculate_texture_index(void);
float			distance(int x1, int y1, int x2, int y2);
void			raycasting(void);
t_ray			*ray(void);
void			render_cube(void);
void			texture_index(int player, int *pos);
int				player_angle(void);
char			*rm_space(char *str);
void			calculate_ray_angle(void);
void			render_cube2(int cube_size, int player, int pos);
t_map			*check_wallhelp(t_map *map1);

#endif