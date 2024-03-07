/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:47:16 by matilde           #+#    #+#             */
/*   Updated: 2024/03/07 13:18:14 by matilde          ###   ########.fr       */
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

//the map is here in this linked list (line)
typedef struct s_map
{
	int				len;
	int				i;
	char			*line;
	struct s_map	*prev;
	struct s_map	*next;
}				t_map;

//has the max length of the map and the position of the camera 
typedef struct s_map_global
{
	int				pos_x;
	int				pos_y;
	int				fd;
	char			*path;
	char			*gnl;
	int				x_max;
	int				y_max;
}				t_map_global;

//has the window and the images
typedef struct s_window
{
	char	*window_ptr;
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

//has the angle, distance of the raycasting and if the way hit the wall
typedef struct s_ray
{
	float		angle;
	int			hit_wall;
	float		distance;
	float		x;
	float		y;
}				t_ray;

t_map			*map(void);
t_texture		*texture(void);
void			printin(int i);
t_window		*window(void);
void			parsing(char *path);
void			check_wall(void);
int				key_handler(int key);
int				free_all(int i);
void			error(char	*str);
char			*get_next_line(int fd);
char			*ft_strjoin1(char *linha, char *buffer);
void			check_map(char *path);
void			init_map(void);
void			check_map(char *path);
char			*rm_nl(char	*str);
void			check_chars(void);
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
void			textur_mapping(t_map *map1);
void			raycasting(int z, int y, int x);
t_ray			*ray(void);
void			coordenates(int *z, int *y, int *x, int a);

#endif