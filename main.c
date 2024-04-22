/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+		+#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/03/20 11:09:27 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/inc/libft.h"

char	map_iter(int x, int y)
{
	int		i;
	int		j;
	t_map	*it;

	i = -1;
	j = -1;
	it = map();
	while (++i <= x)
	{
		while (++j <= y && it->line[j] != '\0')
			return (it->line[j]);
		it = it->next;
	}
	return (' ');
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error("Number of arguments");
	window()->image = NULL;
	parsing(argv[1]);
	new_window();
	mlx_key_hook(window()->win, key_handler, NULL);
	mlx_hook(window()->win, 17, 131072, &free_all, NULL);
	if (window()->win)
		mlx_loop(window()->mlx);
	free_all(0);
	return (0);
}

void	error(char *str)
{
	int	i;

	i = -1;
	write(2, "Error\n", 6);
	while (str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 1);
	free_all(1);
	exit(1);
}

int	err_out(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}
