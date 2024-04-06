/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:01 by matde-je          #+#    #+#             */
/*   Updated: 2024/04/06 14:22:23 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*if read returns 0 means end of file and while loop terminates there
buffer is static so needs to be 0 if an error occured (read returns -1)*/
char	*ft_strchr1(char *str, int c)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (&str[i]);
	}
	return (NULL);
}

void	ft_strcpy(char *str, char *str2)
{
	size_t	j;

	j = -1;
	while (str2[++j])
		str[j] = str2[j];
	str[j] = '\0';
}

char    *ft_strjoin1(char *str1, char *str2)
{
	char	*line;

	if (!str1 || !str2)
		return (NULL);
	line = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!line)
		return (NULL);
	ft_strcpy(line, str1);
	ft_strcpy(line + ft_strlen(str1), str2);
	free(str1);
	return (line);
}

char *ft_strdup1(char *str)
{
	char    *str1;

	str1 = malloc(ft_strlen(str) + 1);
	if (!str1)
		return (NULL);
	ft_strcpy(str1, str);
	return (str1);
}

char    *get_next_line(int fd, int i, int e, char *line)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*new_line;

	line = ft_strdup1(buf);
	while (!ft_strchr1(line, '\n') && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		line = ft_strjoin1(line, buf);
	}
	if (ft_strlen(line) == 0)
		return(free(line), NULL);
	new_line = ft_strchr1(line, '\n');
	if (new_line)
	{
		e = new_line - line + 1;
		ft_strcpy(buf, new_line + 1);
	}
	else
	{
		e = ft_strlen(line);
		buf[0] = '\0';
	}
	line[e] = '\0';
	return (line);
}
