/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:18:06 by matilde           #+#    #+#             */
/*   Updated: 2024/02/15 15:23:57 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_chars(void)
{
	int	count;
	int	pos;
	int	count2;

	count = 0;
	pos = 0;
	while (++count < map()->size_y - 1)
	{
		count2 = 0;
		while (++count2 < map()->size_x)
		{
			if (map()->matrix[count][count2] == 'N')
				pos += 1;
			else if (map()->matrix[count][count2] != '0'
					&& map()->matrix[count][count2] != '1')
				error("Invalid contents in map");
		}
	}
	if (pos != 1)
		error("Invalid contents in map");
}

