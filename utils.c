/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:13:10 by matilde           #+#    #+#             */
/*   Updated: 2024/02/24 14:27:05 by matilde          ###   ########.fr       */
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

void	printin(int i)
{
	t_map	*map1;
	int		j;

	map1 = map();
	while (map1 && i == 0)
	{
		printf("i: %d\n", map1->i);
		printf("line: %s\n", map1->line);
		printf("len: %d\n", map1->len);
		map1 = map1->next;
	}
	j = -1;
	while (++j < 7 && i == 1)
		printf("%d", texture()->f[j]);
	printf("\n");
	j = -1;
	while (++j < 6 && i == 1)
		printf("%d", texture()->c[j]);
	printf("\n");
	if (i == 2)
	{
		printf("%s\n", (char *)texture()->no);
		printf("%s\n", (char *)texture()->so);
		printf("%s\n", (char *)texture()->we);
		printf("%s\n", (char *)texture()->ea);
	}
}

void	error(char	*str)
{
	int	i;

	i = -1;
	write(1, "Error\n", 6);
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	free_all(1);
	exit(1);
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
	if (map_global()->path)
		free(map_global()->path);
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

void	freeing(void)
{
	if (texture()->no)
		free(texture()->no);
	if (texture()->so)
		free(texture()->so);
	if (texture()->we)
		free(texture()->we);
	if (texture()->ea)
		free(texture()->ea);
	if (texture()->f)
		free(texture()->f);
	if (texture()->c)
		free(texture()->c);
}
