/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:14:02 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/20 13:25:35 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*rm_nl(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			str[i] = '\0';
	return (str);
}

int	skipspace(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	return (i);
}

char	*rm_space(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if (i <= 0)
		return (NULL);
	while (i > 0 && str[--i])
	{
		if (str[i] == ' ')
			continue ;
		else
			break ;
	}
	if (str[i] != ' ')
		str[i + 1] = '\0';
	return (str);
}

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
