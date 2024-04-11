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

void	prep_texture(int no, int i, char *trim, char *trim1)
{
	static int	so = 0;
	static int	we = 0;
	static int	ea = 0;
	static int	c = 0;
	static int	f = 0;

	while (map_global()->gnl)
	{
		i = 0;
		trim = NULL;
		trim1 = NULL;
		i = skipspace(map_global()->gnl);
		if (map_global()->gnl[i] == '1')
			break ;
		parse_north(&trim, &trim1, i, &no);
		parse_south(&trim, &trim1, i, &so);
		parse_west(&trim, &trim1, i, &we);
		parse_east(&trim, &trim1, i, &ea);
		parse_rgb(&trim, &trim1, &c, &f);
		free(map_global()->gnl);
		(map_global()->gnl) = (get_next_line(map_global()->fd, 0, 0, NULL));
	}
	close(map_global()->fd);
	if (so != 1 || ea != 1 || we != 1 || no != 1 || c != 1 || f != 1)
		free_trim(&trim, &trim1, "Invalid textures", NULL);
}

void	parse_north(char **trim, char **trim1, int i, int *no)
{
	int	fd;

	if (map_global()->gnl[i] == 'N' && map_global()->gnl[i + 1] == 'O')
	{
		*no += 1;
		if (*no != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "N");
		*trim1 = rm_nl(ft_strtrim(*trim, "O"));
		(tex()->no) = rm_space(ft_strtrim(*trim1, " "));
		fd = open(tex()->no, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}

void	parse_south(char **trim, char **trim1, int i, int *so)
{
	int	fd;

	if (map_global()->gnl[i] == 'S' && map_global()->gnl[i + 1] == 'O')
	{
		*so += 1;
		if (*so != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "S");
		*trim1 = ft_strtrim(*trim, "O");
		(tex()->so) = rm_space(rm_nl(ft_strtrim(*trim1, " ")));
		fd = open(tex()->so, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}

void	parse_west(char **trim, char **trim1, int i, int *we)
{
	int	fd;

	if (map_global()->gnl[i] == 'W' && map_global()->gnl[i + 1] == 'E')
	{
		*we += 1;
		if (*we != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "W");
		*trim1 = ft_strtrim(*trim, "E");
		(tex()->we) = rm_space(rm_nl(ft_strtrim(*trim1, " ")));
		fd = open(tex()->we, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}
void	parse_east(char **trim, char **trim1, int i, int *ea)
{
	int	fd;

	if (map_global()->gnl[i] == 'E' && map_global()->gnl[i + 1] == 'A')
	{
		*ea += 1;
		if (*ea != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&map_global()->gnl[i], "E");
		*trim1 = ft_strtrim(*trim, "A");
		(tex()->ea) = rm_space(rm_nl(ft_strtrim(*trim1, " ")));
		fd = open(tex()->ea, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}
