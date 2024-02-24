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

#include "../cub3d.h"

void	prep_texture(char *path)
{
	char	*trim;
	char	*trim1;
	char	*gnl;

	(map_global()->fd) = open(path, O_RDONLY);
	if (map_global()->fd < 0)
		error("Failed to open file");
	map_global()->gnl = get_next_line(map_global()->fd);
	if (!map_global()->gnl)
		error("Invalid map");
	while (map_global()->gnl)
	{
		trim = NULL;
		trim1 = NULL;
		gnl = map_global()->gnl;
		while (*map_global()->gnl == ' ')
			map_global()->gnl++;
		if (*map_global()->gnl == '1')
			break ;
		parse_textures(&trim, &trim1);
		parse_rgb(&trim, &trim1);
		free(gnl);
		map_global()->gnl = get_next_line(map_global()->fd);
		if (!map_global()->gnl)
			error("Invalid map");
	}
	free(gnl);
	close(map_global()->fd);
}

void	parse_textures(char **trim, char **trim1)
{
	if (*map_global()->gnl == 'N' && *(map_global()->gnl + 1) == 'O')
	{
		map_global()->no += 1;
		if (map_global()->no != 1)
			error("Invalid texture");
		*trim = ft_strtrim(map_global()->gnl, "N");
		*trim1 = ft_strtrim(*trim, "O");
		(texture()->no) = ft_strtrim(*trim1, " ");
	}
	else if (*map_global()->gnl == 'S' && *(map_global()->gnl + 1) == 'O')
	{
		map_global()->so += 1;
		if (map_global()->so != 1)
			error("Invalid texture");
		*trim = ft_strtrim(map_global()->gnl, "S");
		*trim1 = ft_strtrim(*trim, "O");
		(texture()->so) = ft_strtrim(*trim1, " ");
	}
	else
		count_texture(trim, trim1);
}

void	count_texture(char **trim, char **trim1)
{
	if (*map_global()->gnl == 'W' && *(map_global()->gnl + 1) == 'E')
	{
		map_global()->we += 1;
		if (map_global()->we != 1)
			error("Invalid texture");
		*trim = ft_strtrim(map_global()->gnl, "W");
		*trim1 = ft_strtrim(*trim, "E");
		(texture()->we) = ft_strtrim(*trim1, " ");
	}
	else if (*map_global()->gnl == 'E' && *(map_global()->gnl + 1) == 'A')
	{
		*trim = ft_strtrim(map_global()->gnl, "E");
		*trim1 = ft_strtrim(*trim, "A");
		(texture()->ea) = ft_strtrim(*trim1, " ");
		map_global()->ea += 1;
	}
}
