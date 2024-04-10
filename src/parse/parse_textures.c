/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:48 by matilde           #+#    #+#             */
/*   Updated: 2024/02/20 14:33:56 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	prep_texture(char *path, int i, char *trim, char *trim1)
{
	(map_global()->fd) = open(path, O_RDONLY);
	if (map_global()->fd < 0)
		error("Failed to open file");
	(map_global()->gnl) = (get_next_line(map_global()->fd, 0, 0, NULL));
	if (!map_global()->gnl)
	{
		close(map_global()->fd);
		error("Invalid map");
	}
	while (map_global()->gnl)
	{
		i = 0;
		trim = NULL;
		trim1 = NULL;
		while (map_global()->gnl[i] == ' ')
			i++;
		if (map_global()->gnl[i] == '1')
			break ;
		parse_textures(&trim, &trim1, i);
		parse_rgb(&trim, &trim1, i);
		free(map_global()->gnl);
		(map_global()->gnl) = (get_next_line(map_global()->fd, 0, 0, NULL));
	}
	close(map_global()->fd);
}

void	parse_textures(char **trim, char **trim1, int i)
{
	static int	no = 0;
	static int	so = 0;

	if (map_global()->gnl[i] == 'N' && map_global()->gnl[i + 1] == 'O')
	{
		no += 1;
		if (no != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "N");
		*trim1 = rm_nl(ft_strtrim(*trim, "O"));
		(tex()->no) = ft_strtrim(*trim1, " ");
		open1(tex()->no, trim, trim1);
	}
	else if (map_global()->gnl[i] == 'S' && map_global()->gnl[i + 1] == 'O')
	{
		so += 1;
		if (so != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "S");
		*trim1 = ft_strtrim(*trim, "O");
	}
	count_texture(trim, trim1, i);
}

void	count_texture(char **trim, char **trim1, int i)
{
	static int	we = 0;
	static int	ea = 0;

	if (map_global()->gnl[i] == 'S' && map_global()->gnl[i + 1] == 'O')
		south(trim, trim1);
	else if (map_global()->gnl[i] == 'W' && map_global()->gnl[i + 1] == 'E')
	{
		we += 1;
		if (we != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "W");
		*trim1 = ft_strtrim(*trim, "E");
		(tex()->we) = rm_nl(ft_strtrim(*trim1, " "));
		open1(tex()->we, trim, trim1);
	}
	else if (map_global()->gnl[i] == 'E' && map_global()->gnl[i + 1] == 'A')
	{
		ea += 1;
		if (ea != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "E");
		*trim1 = ft_strtrim(*trim, "A");
		(tex()->ea) = rm_nl(ft_strtrim(*trim1, " "));
		open1(tex()->ea, trim, trim1);
	}
}

void	south(char **trim, char **trim1)
{
	(tex()->so) = rm_nl(ft_strtrim(*trim1, " "));
	open1(tex()->so, trim, trim1);
}
void	open1(void *path, char **trim, char **trim1)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		free_trim(trim, trim1, "Invalid texture", NULL);
	close(fd);
}
