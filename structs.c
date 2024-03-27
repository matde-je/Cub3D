/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:23:31 by matilde           #+#    #+#             */
/*   Updated: 2024/03/13 22:37:12 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_texture	*texture(void)
{
	static t_texture	var;

	return (&var);
}

t_ray	*ray(void)
{
	static t_ray	var;

	return (&var);
}
