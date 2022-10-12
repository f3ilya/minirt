/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:12:05 by                   #+#    #+#             */
/*   Updated: 2021/12/25 18:53:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_strchri(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

static int	extract_line(int fd, char *rest, char **line)
{
	char	*tmp;
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	*line = rest;
	ret = 0;
	while (ft_strchri(*line, '\n') == -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		tmp = ft_strjoin(*line, buf);
		free(*line);
		if (!(*tmp))
			return (-1);
		*line = tmp;
	}
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;
	int			index_nl;

	line = NULL;
	if (BUFFER_SIZE <= 0 || extract_line(fd, rest, &line) < 0)
	{
		free(line);
		return (NULL);
	}
	rest = NULL;
	index_nl = ft_strchri(line, '\n');
	if (index_nl >= 0)
	{
		if (index_nl != (int)ft_strlen(line) - 1)
			rest = ft_strdup(line + index_nl + 1);
		line[index_nl] = '\0';
	}
	return (line);
}
