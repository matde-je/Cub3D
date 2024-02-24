/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:57:22 by matilde           #+#    #+#             */
/*   Updated: 2024/02/24 13:18:39 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_rgb(char **trim, char **trim1)
{
	char	**split;
	int		j;

	j = parse_rgb2(trim, trim1, &split);
	if (*map_global()->gnl == 'F')
	{
		map_global()->f += 1;
		if (map_global()->f != 1)
			error("Invalid color");
		texture()->f = (int *)malloc(sizeof(int) * (ft_strlen(*trim1) - 1));
		rgb_f(-1, split, 0);
		texture()->f[ft_strlen(*trim1) - 2] = '\0';
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
	j = -1;
}

int	parse_rgb2(char **trim, char **trim1, char ***split)
{
	int		j;

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
		map_global()->c += 1;
		if (map_global()->c != 1)
			error("Invalid color");
		texture()->c = (int *)malloc(sizeof(int) * (ft_strlen(*trim1) - 1));
		rgb_c(-1, *split, 0);
		texture()->c[ft_strlen(*trim1) - 2] = '\0';
	}
	return (0);
}

void	rgb_c(int j, char **split, int e)
{
	while (split[++j])
	{
		if (ft_atoi(split[j]) >= 10 && ft_atoi(split[j]) < 100)
		{
			texture()->c[e] = ft_atoi(split[j]) / 10;
			texture()->c[e + 1] = ft_atoi(split[j]) % 10;
			e++;
		}
		else if (ft_atoi(split[j]) < 10)
			texture()->c[e] = ft_atoi(split[j]);
		else
		{
			texture()->c[e] = ft_atoi(split[j]) / 100;
			texture()->c[e + 1] = (ft_atoi(split[j]) % 100) / 10;
			texture()->c[e + 2] = (ft_atoi(split[j]) % 100) % 10;
			e += 2;
		}
		e++;
	}
}

void	rgb_f(int j, char **split, int e)
{
	while (split[++j])
	{
		if (ft_atoi(split[j]) >= 10 && ft_atoi(split[j]) < 100)
		{
			texture()->f[e] = ft_atoi(split[j]) / 10;
			texture()->f[e + 1] = ft_atoi(split[j]) % 10;
			e++;
		}
		else if (ft_atoi(split[j]) < 10)
			texture()->f[e] = ft_atoi(split[j]);
		else
		{
			texture()->f[e] = ft_atoi(split[j]) / 100;
			texture()->f[e + 1] = (ft_atoi(split[j]) % 100) / 10;
			texture()->f[e + 2] = (ft_atoi(split[j]) % 100) % 10;
			e += 2;
		}
		e++;
	}
}
