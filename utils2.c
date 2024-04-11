/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:38:37 by matilde           #+#    #+#             */
/*   Updated: 2024/04/11 11:36:14 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_textures(char *path)
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
	if (map_global()->gnl)
		free(map_global()->gnl);
	if (map_global()->path)
		free(map_global()->path);
	if (window()->mlx)
	{
		mlx_destroy_display(window()->mlx);
		free(window()->mlx);
	}
	if (i == 0)
		exit(0);
	return (0);
}

void	freeing(void)
{
	if (window()->win)
		mlx_destroy_window(window()->mlx, window()->win);
	if (tex()->no)
		free(tex()->no);
	if (tex()->so)
		free(tex()->so);
	if (tex()->we)
		free(tex()->we);
	if (tex()->ea)
		free(tex()->ea);
	if (tex()->f)
		free(tex()->f);
	if (tex()->c)
		free(tex()->c);
	if (window()->image && window()->image->img_ptr)
	{
		mlx_destroy_image(window()->mlx, window()->image->img_ptr);
		free(window()->image);	
	}
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

t_c3d	*cub3(void)
{
	static t_c3d	cub3;

	return (&cub3);
}
