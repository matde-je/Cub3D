/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:01 by matde-je          #+#    #+#             */
/*   Updated: 2024/02/15 16:41:07 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*if read returns 0 means end of file and while loop terminates there
buffer is static so needs to be 0 if an error occured (read returns -1)*/

int	buffer(char *buf)
{
	int			i;
	int			trig;
	int			j;

	trig = 0;
	i = 0;
	j = 0;
	while (buf[i] != '\0')
	{
		if (trig == 1)
		{
			buf[j] = buf[i];
			j++;
		}
		if (buf[i] == '\n')
			trig = 1;
		buf[i] = 0;
		i++;
	}
	return (trig);
}

void	clearbuffer(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		buf[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX];
	char		*line;
	int			trig;

	if (fd >= FOPEN_MAX || read(fd, 0, 0) == -1)
	{
		clearbuffer(buf);
		return (NULL);
	}
	line = NULL;
	trig = 0;
	while (trig == 0 && (buf[0] != 0 || read(fd, buf, FOPEN_MAX) != 0))
	{
		line = ft_strjoin1(line, buf);
		trig = buffer(buf);
	}
	return (line);
}

/*int	main()
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
}*/