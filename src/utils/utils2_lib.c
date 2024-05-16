/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:00:05 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 19:37:04 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	tmp = ft_substr(s1, 0, i + 1);
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (l < len)
		return (ft_strdup((char *)&s[start]));
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < l && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

static void	stralloc(char const *s, char c, char **arr, int i)
{
	int	char_count;

	char_count = 0;
	while (*s != c && *s)
	{
		char_count++;
		s++;
	}
	arr[i] = (char *)malloc(sizeof(char) * (char_count + 1));
	if (!arr[i])
	{
		while (i--)
			free(arr[i]);
		free(arr);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		str_count;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str_count = ft_wordcount(s, c);
	arr = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i != str_count)
	{
		while (*s == c && *s)
			s++;
		stralloc(s, c, arr, i);
		j = 0;
		while (*s != c && *s)
			arr[i][j++] = (char)*s++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		a;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	a = 0;
	c = 0;
	while (s1[a])
		res[c++] = s1[a++];
	a = 0;
	while (s2[a])
		res[c++] = s2[a++];
	res[c] = '\0';
	return (res);
}
