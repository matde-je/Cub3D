/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:57:22 by matilde           #+#    #+#             */
/*   Updated: 2024/05/16 18:15:07 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_rgb(char **trim, char **trim1, int *f, int *c)
{
	char	**split;
	int		i;

	i = skipspace(c3d()->mg.gnl);
	free_trim(trim, trim1, NULL, NULL);
	if (c3d()->mg.gnl[i] && c3d()->mg.gnl[i] != 'C' && c3d()->mg.gnl[i] != 'F')
		return ;
	parse_rgb2(trim, trim1, &split, i);
	if (c3d()->mg.gnl[i] == 'C')
	{
		*c += 1;
		if (*c != 1)
			free_trim(trim, trim1, "Invalid color", &split);
		rgb_c(-1, split, 0);
	}
	if (c3d()->mg.gnl[i] == 'F')
	{
		*f += 1;
		if (*f != 1)
			free_trim(trim, trim1, "Invalid color", &split);
		rgb_f(-1, split, 0);
	}
	free_trim(trim, trim1, NULL, &split);
}

void	parse_rgb2(char **trim, char **trim1, char ***split, int i)
{
	char	*trim2;
	int		j;

	if (c3d()->mg.gnl[i] == 'C')
		*trim = ft_strtrim(&c3d()->mg.gnl[i], "C");
	else
		*trim = ft_strtrim(&c3d()->mg.gnl[i], "F");
	*trim1 = ft_strtrim(*trim, " ");
	trim2 = rm_space(rm_nl(*trim1));
	if (!trim2)
		free_trim(trim, trim1, "Invalid color", NULL);
	*split = ft_split(*trim1, ',');
	j = -1;
	while ((*split)[++j])
	{
		i = skipspace((*split)[j]) - 1;
		while ((*split)[j][++i] && i < (int)ft_strlen((*split)[j]))
			if ((*split)[j][i] != ' ' && ((*split)[j][i] < '0'
					|| (*split)[j][i] > '9' || ft_atoi((*split)[j]) < 0
					|| ft_atoi((*split)[j]) > 255))
				free_trim(trim, trim1, "Invalid color", split);
	}
	if (j < 3)
		free_trim(trim, trim1, "Invalid color", split);
}

void	rgb_c(int j, char **split, int e)
{
	int	red;
	int	green;
	int	blue;

	c3d()->t.c = (int *)malloc(sizeof(int) * 4);
	while (split[++j])
	{
		c3d()->t.c[e] = ft_atoi(split[j]);
		e++;
	}
	red = c3d()->t.c[0];
	green = c3d()->t.c[1];
	blue = c3d()->t.c[2];
	c3d()->t.c[3] = (red << 16) | (green << 8) | blue;
}

void	rgb_f(int j, char **split, int e)
{
	int	red;
	int	green;
	int	blue;

	c3d()->t.f = (int *)malloc(sizeof(int) * 4);
	while (split[++j])
	{
		c3d()->t.f[e] = ft_atoi(split[j]);
		e++;
	}
	red = c3d()->t.f[0];
	green = c3d()->t.f[1];
	blue = c3d()->t.f[2];
	c3d()->t.f[3] = (red << 16) | (green << 8) | blue;
}

void	free_trim(char **trim, char **trim1, char *message, char ***split)
{
	int	j;

	j = -1;
	if (*trim1)
		free(*trim1);
	if (*trim)
		free(*trim);
	if (split != NULL && *split && **split)
	{
		while ((*split)[++j])
			free((*split)[j]);
		free(*split);
	}
	if (message)
		error(message);
}
