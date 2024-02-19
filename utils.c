/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:13:10 by matilde           #+#    #+#             */
/*   Updated: 2024/02/19 16:48:23 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*rm_nl(char	*str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	printin(void)
{
	t_map	*map1;

	map1 = map();
	printf("------printin---------\n");
	while (map1)
	{
		printf("line: %s\n", map1->line);
		printf("len: %d\n", map1->len);
		printf("i: %d\n", map1->i);
		map1 = map1->next;
	}
	printf("------printin---------\n");
}

// char	*rm_space(const char *str)
// {
// 	char	*str1;
// 	int		i;
// 	int		j;

// 	str1 = malloc(ft_strlen(str) + 1);
// 	if (str1 == NULL)
// 		error("Memory allocation failed");
// 	i = -1;
// 	j = 0;
// 	while (++i < (int)ft_strlen(str))
// 	{
// 		if (str[i] != ' ')
// 		{
// 			str1[j] = str[i];
// 			j++;
// 		}
// 	}
// 	str1[j] = '\0';
// 	return (str1);
// }

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
	if (window()->window_ptr)
		mlx_destroy_window(window()->mlx_ptr, window()->window_ptr);
	if (window()->mlx_ptr)
	{
		mlx_destroy_display(window()->mlx_ptr);
		free(window()->mlx_ptr);
	}
	if (i == 0)
		exit(0);
	return (0);
}
