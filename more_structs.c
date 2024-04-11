/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:38:37 by matilde           #+#    #+#             */
/*   Updated: 2024/04/10 17:39:21 by matilde          ###   ########.fr       */
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

t_c3d	*cub3(void)
{
	static t_c3d	cub3;

	return (&cub3);
}
