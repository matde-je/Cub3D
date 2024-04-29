/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:23:31 by matilde           #+#    #+#             */
/*   Updated: 2024/03/13 22:37:12 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map_global	*map_global(void)
{
	static t_map_global	var;

	return (&var);
}

t_window	*window(void)
{
	static t_window	var;

	return (&var);
}

t_player *player(void)
{
    static t_player var;

    var = (t_player){'\0', {0, 0}, {0, 0}, {0, 0}, false, 0, 0, 0};
    return (&var);
}

t_texture	*tex(void)
{
	static t_texture	var;
    var = (t_texture){NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0,
        0, 0};
	return (&var);
}

t_ray	*ray(void)
{
	static t_ray	var;
    var = (t_ray){0, 0, 0, 0, 0, {0, 0}, {0, 0}, {0, 0}, 0, 0, {0, 0}, 0,
        {0, 0}, 0, 0, 0, 0, 0, 0};
	return (&var);
}
