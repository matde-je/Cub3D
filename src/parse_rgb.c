/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:57:22 by matilde           #+#    #+#             */
/*   Updated: 2024/03/05 13:06:53 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_rgb(char **trim, char **trim1)
{
	char		**split;
	int			j;
	static int	f = 0;

	j = parse_rgb2(trim, trim1, &split);
	if (*map_global()->gnl == 'F')
	{
		f += 1;
		if (f != 1)
			error("Invalid color");
		texture()->f = (int *)malloc(sizeof(int) * 4);
		rgb_f(-1, split, 0);
	}
	if (j == 0)
	{
		j = -1;
		while (split[++j])
			free(split[j]);
		free(split);
	}
	if (*trim1)
		free(*trim1);
	if (*trim)
		free(*trim);
}

int	parse_rgb2(char **trim, char **trim1, char ***split)
{
	int			j;
	static int	c = 0;

	if (*map_global()->gnl != 'C' && *map_global()->gnl != 'F')
		return (1);
	if (*map_global()->gnl == 'C')
		*trim = ft_strtrim(map_global()->gnl, "C");
	else
		*trim = ft_strtrim(map_global()->gnl, "F");
	*trim1 = ft_strtrim(*trim, " ");
	*split = ft_split(*trim1, ',');
	j = -1;
	while ((*split)[++j])
		if (ft_atoi((*split)[j]) < 0 || ft_atoi((*split)[j]) > 255)
			error("Invalid color");
	if (*map_global()->gnl == 'C')
	{
		c += 1;
		if (c != 1)
			error("Invalid color");
		texture()->c = (int *)malloc(sizeof(int) * 4);
		rgb_c(-1, *split, 0);
	}
	return (0);
}

void	rgb_c(int j, char **split, int e)
{
	int	red;
	int	green;
	int	blue;

	while (split[++j])
	{
		texture()->c[e] = ft_atoi(split[j]);
		e++;
	}
	red = texture()->c[0];
	green = texture()->c[1];
	blue = texture()->c[2];
	texture()->c[3] = (red << 16) | (green << 8) | blue;
}

void	rgb_f(int j, char **split, int e)
{
	int	red;
	int	green;
	int	blue;

	while (split[++j])
	{
		texture()->f[e] = ft_atoi(split[j]);
		e++;
	}
	red = texture()->f[0];
	green = texture()->f[1];
	blue = texture()->f[2];
	texture()->f[3] = (red << 16) | (green << 8) | blue;
}
