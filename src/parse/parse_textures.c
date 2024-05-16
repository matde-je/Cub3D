/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:48 by matilde           #+#    #+#             */
/*   Updated: 2024/02/20 14:33:56 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	prep_texture(int no, int i, char *trim, char *trim1)
{
	static int	so = 0;
	static int	we = 0;
	static int	ea = 0;
	static int	ce = 0;
	static int	f = 0;

	while (c3d()->mg.gnl)
	{
		i = 0;
		trim = NULL;
		trim1 = NULL;
		i = skipspace(c3d()->mg.gnl);
		if (c3d()->mg.gnl[i] == '1')
			break ;
		parse_north(&trim, &trim1, i, &no);
		parse_south(&trim, &trim1, i, &so);
		parse_west(&trim, &trim1, i, &we);
		parse_east(&trim, &trim1, i, &ea);
		parse_rgb(&trim, &trim1, &ce, &f);
		free(c3d()->mg.gnl);
		(c3d()->mg.gnl) = (get_next_line(c3d()->mg.fd, 0, 0, NULL));
	}
	close(c3d()->mg.fd);
	if (so != 1 || ea != 1 || we != 1 || no != 1 || ce != 1 || f != 1)
		free_trim(&trim, &trim1, "Invalid textures", NULL);
}

void	parse_north(char **trim, char **trim1, int i, int *no)
{
	int		fd;
	char	*str;

	if (c3d()->mg.gnl[i] == 'N' && c3d()->mg.gnl[i + 1] == 'O')
	{
		*no += 1;
		if (*no != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&c3d()->mg.gnl[i], "N");
		*trim1 = rm_nl(ft_strtrim(*trim, "O"));
		(c3d()->t.so) = rm_space(ft_strtrim(*trim1, " "));
		str = (char *)c3d()->t.so;
		if (str[ft_strlen(str) - 4] != '.' && str[ft_strlen(str) - 4] != 'x' && \
			str[ft_strlen(str) - 4] != 'p' && str[ft_strlen(str) - 4] != 'm')
			free_trim(trim, trim1, "Invalid texture path", NULL);
		fd = open(c3d()->t.so, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}

void	parse_south(char **trim, char **trim1, int i, int *so)
{
	int		fd;
	char	*str;

	if (c3d()->mg.gnl[i] == 'S' && c3d()->mg.gnl[i + 1] == 'O')
	{
		*so += 1;
		if (*so != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&c3d()->mg.gnl[i], "S");
		*trim1 = ft_strtrim(*trim, "O");
		(c3d()->t.no) = rm_space(rm_nl(ft_strtrim(*trim1, " ")));
		str = (char *)c3d()->t.no;
		if (str[ft_strlen(str) - 4] != '.' && str[ft_strlen(str) - 4] != 'x' && \
		str[ft_strlen(str) - 4] != 'p' && str[ft_strlen(str) - 4] != 'm')
			free_trim(trim, trim1, "Invalid texture path", NULL);
		fd = open(c3d()->t.no, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}

void	parse_west(char **trim, char **trim1, int i, int *we)
{
	int		fd;
	char	*str;

	if (c3d()->mg.gnl[i] == 'W' && c3d()->mg.gnl[i + 1] == 'E')
	{
		*we += 1;
		if (*we != 1)
			error("Invalid texture");  
		*trim = ft_strtrim(&c3d()->mg.gnl[i], "W");
		*trim1 = ft_strtrim(*trim, "E");
		(c3d()->t.ea) = rm_space(rm_nl(ft_strtrim(*trim1, " ")));
		str = (char *)c3d()->t.ea;
		if (str[ft_strlen(str) - 4] != '.' && str[ft_strlen(str) - 4] != 'x' && \
			str[ft_strlen(str) - 4] != 'p' && str[ft_strlen(str) - 4] != 'm')
			free_trim(trim, trim1, "Invalid texture path", NULL);
		fd = open(c3d()->t.ea, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}
void	parse_east(char **trim, char **trim1, int i, int *ea)
{
	int		fd;
	char	*str;

	if (c3d()->mg.gnl[i] == 'E' && c3d()->mg.gnl[i + 1] == 'A')
	{
		*ea += 1;
		if (*ea != 1)
			error("Invalid texture");
		*trim = ft_strtrim(&c3d()->mg.gnl[i], "E");
		*trim1 = ft_strtrim(*trim, "A");
		(c3d()->t.we) = rm_space(rm_nl(ft_strtrim(*trim1, " ")));
		str = (char *)c3d()->t.we;
		if (str[ft_strlen(str) - 4] != '.' && str[ft_strlen(str) - 4] != 'x' && \
			str[ft_strlen(str) - 4] != 'p' && str[ft_strlen(str) - 4] != 'm')
			free_trim(trim, trim1, "Invalid texture path", NULL);
		fd = open(c3d()->t.we, O_RDONLY);
		if (fd == -1)
			free_trim(trim, trim1, "Invalid texture", NULL);
		close(fd);
	}
}
