/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:25:51 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 19:26:10 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*gnl(int fd, int i, char *buf, char *line)
{
	while (1)
	{
		if (ft_strchr1(line, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
		{
			if (ft_strlen(line) == 0)
				return (free(line), NULL);
			break ;
		}
		buf[i] = '\0';
		line = ft_strjoin1(line, buf);
	}
	return (line);
}
