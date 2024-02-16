/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by matilde           #+#    #+#             */
/*   Updated: 2024/02/16 18:04:59 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_name(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'c')
		&& (path[i - 2] == 'u' && path[i - 1] == 'b'))
	{
		check_map(path);
		//check_wall();
	}
	else
		error("Invalid map");
}

void	check_map(char *path)
{
	int		fd;
	char	*gnl;
	int		i;

	fd = open(path, O_RDONLY);
	gnl = get_next_line(fd);
	if (!gnl)
		error("Invalid map");
	while (gnl)
	{
		i = 0;
		while (gnl[i] && gnl[i] == ' ')
			i++;
		if (gnl[i] != '1')
		{
			free(gnl);
			gnl = get_next_line(fd);
		}
		else
			break ;
	}
	if (gnl[i] == '1')
		init_map(gnl, fd);
	free(gnl);
	close(fd);
}

//doesnt have to be rectangle, but walls still need to be 1 
void	init_map(char *gnl, int fd)
{
	t_map	*map1;
	int		max;
	int		i;

	map1 = map(0);
	max = 0;
	while (gnl != NULL)
	{
		gnl = rm_space(rm_nl(gnl));
		map1->line = malloc(ft_strlen(gnl) + 1);
		if (map1->line == NULL)
			error("Fail to allocate memory");
		ft_strcpy(map1->line, gnl);
		map1->i += 1;
		i = map1->i;
		map1->len = ft_strlen(map1->line);
		if (map1->len > max)
			max = map1->len;
		free(gnl);
		gnl = get_next_line(fd);
		if (gnl != NULL)
		{
			map1->next = malloc(sizeof(t_map));
			if (map1->next == NULL)
				error("Fail to allocate memory");
			map1->next->prev = map1;
		}
		else
			map1->next = NULL;
		map1 = map1->next;
	}
	map_global()->x_max = max;
	map_global()->y_max = i;
	printin();
}



// void	check_size(void)
// {
//  if (len < 3 || i < 3)
//  	error("Invalid map");
// }

// void	check_wall(void)
// {
// 	int		count;

// 	count = -1;
// 	while (++count < map(0)->len)
// 	{
// 		if ((map(0)->line[0] != '1' 
// 			|| map(0)->line[map(0)->i -1] != '1'))
// 			error("Invalid walls of map");
// 	}
// 	count = 0;
// 	while (++count < map(0)->i)
// 	{
// 		if ((map(0)->line[count] != '1' 
// 			|| map(0)->line[count] != '1'))
// 			error("Invalid walls of map");
// 	}
// 	check_chars();
// }

// void	check_chars(void)
// {
// 	int	count;
// 	int	pos;
// 	int	count2;

// 	count = 0;
// 	pos = 0;
// 	while (++count < map(0)->i - 1)
// 	{
// 		count2 = 0;
// 		while (++count2 < map(0)->len)
// 		{
// 			if (map(0)->line[count] == 'N')
// 				pos += 1;
// 			else if (map(0)->line[count] != '0' 
// 					&& map(0)->line[count] != '1')
// 				error("Invalid contents in map");
// 		}
// 	}
// 	if (pos != 1)
// 		error("Invalid contents in map");
// }
