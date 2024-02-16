/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/02/16 18:01:02 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error("Error in number of arguments");
	check_name(argv[1]);
	new_window();
	mlx_key_hook(window()->window_ptr, key_handler, NULL);
	mlx_hook(window()->window_ptr, 17, 131072, &free_all, NULL);
	if (window()->window_ptr)
		mlx_loop(window()->mlx_ptr);
	free_all(0);
	return (0);
}

void	error(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	free_all(1);
}

t_map	*map(t_map *new_map)
{
	static t_map	*var = NULL;

	if (new_map != NULL)
	{
		if (var != NULL)
		{
			free(var->line);
			free(var);
		}
		var = new_map;
	}
	else if (var == NULL)
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

t_map_global	*map_global(void)
{
	static t_map_global	var;

	return (&var);
}

t_window	*window(void)
{
	static t_window		var;

	return (&var);
}
