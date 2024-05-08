/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:13:10 by matilde           #+#    #+#             */
/*   Updated: 2024/04/29 22:17:18 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	while (str[i] == ' ')
		i++;
	return (i);
}

char	*rm_space(char *str)
{
	int	i;

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

void	printin(int i)
{
	t_map	*map1;
	int		j;

	map1 = map();
	while (map1 && i == 0)
	{
		printf("i: %d\n", map1->i);
		printf("line: %s.\n", map1->line);
		printf("len: %d\n", map1->len);
		map1 = map1->next;
	}
	j = -1;
	while (++j < 7 && i == 1)
		printf("%d", c3d()->t.f[j]);
	printf("\n");
	j = -1;
	while (++j < 6 && i == 1)
		printf("%d", c3d()->t.c[j]);
	printf("\n");
	if (i == 2)
	{
		printf("%s\n", (char *)c3d()->t.no);
		printf("%s\n", (char *)c3d()->t.so);
		printf("%s\n", (char *)c3d()->t.we);
		printf("%s\n", (char *)c3d()->t.ea);
	}
}

// if (window()->img['N'])
// 	mlx_destroy_image(window()->mlx, window()->img['N']);
// if (window()->img['S'])
// 	mlx_destroy_image(window()->mlx, window()->img['S']);
// if (window()->img['E'])
// 	mlx_destroy_image(window()->mlx, window()->img['E']);
// if (window()->img['W'])
// 	mlx_destroy_image(window()->mlx, window()->img['W']);
