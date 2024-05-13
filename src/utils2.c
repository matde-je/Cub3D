/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:38:37 by matilde           #+#    #+#             */
/*   Updated: 2024/04/29 22:17:35 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	open_textures(char *path)
{
	(c3d()->mg.fd) = open(path, O_RDONLY);
	if (c3d()->mg.fd < 0)
		error("Failed to open file");
	(c3d()->mg.gnl) = (get_next_line(c3d()->mg.fd, 0, 0, NULL));
	if (!c3d()->mg.gnl)
	{
		close(c3d()->mg.fd);
		error("Invalid texture");
	}
}

char	map_iter(int x, int y)
{
	int		i;
	int		j;
	t_map	*it;

	i = -1;
	it = map();
	while (++i <= x && it != NULL)
	{
		j = -1;
		while (++j <= y && it->line[j] != '\0')
		{
			if (i == x && j == y)
				return (it->line[j]);
		}
		it = it->next;
	}
	return (' ');
}

int	free_all(int i)
{
	t_map	*next;
	t_map	*current;

	current = map();
	while (current != NULL)
	{
		free(current->line);
		next = current->next;
		free(current);
		current = next;
	}
	freeing();
	if (c3d()->mg.gnl)
		free(c3d()->mg.gnl);
	if (c3d()->mg.path)
		free(c3d()->mg.path);
	if (c3d()->mlx)
	{
		mlx_destroy_display(c3d()->mlx);
		free(c3d()->mlx);
	}
	if (i == 0)
		exit(0);
	return (0);
}

void	freeing(void)
{
	if (c3d()->win)
		mlx_destroy_window(c3d()->mlx, c3d()->win);
	if (c3d()->t.no)
		free(c3d()->t.no);
	if (c3d()->t.so)
		free(c3d()->t.so);
	if (c3d()->t.we)
		free(c3d()->t.we);
	if (c3d()->t.ea)
		free(c3d()->t.ea);
	if (c3d()->t.f)
		free(c3d()->t.f);
	if (c3d()->t.c)
		free(c3d()->t.c);
	// if (c3d()->image.ptr)
		// mlx_destroy_image(c3d()->mlx, c3d()->image.ptr);
}

t_map	*map(void)
{
	static t_map	*var = NULL;

	if (var == NULL)
	{
		var = malloc(sizeof(t_map));
		if (var == NULL)
			error("alloc fail");
		var->line = NULL;
		var->i = 0;
		var->prev = NULL;
		var->next = NULL;
	}
	return (var);
}

