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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bonus.h"

static void	print_error_obj(const size_t n)
{
	ft_putstr_fd("(l: ", 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd(")\n", 2);
}

static int	add_obj(t_disp *display, char **split_line)
{
	if (!ft_strncmp(split_line[0], "A", ft_strlen(split_line[0])))
		return (set_ambient(display, split_line));
	else if (!ft_strncmp(split_line[0], "C", ft_strlen(split_line[0])))
		return (set_camera(display, split_line));
	else if (!ft_strncmp(split_line[0], "L", ft_strlen(split_line[0])))
		return (add_light(display, split_line));
	else if (!ft_strncmp(split_line[0], "sp", ft_strlen(split_line[0])))
		return (add_sphere(display, split_line));
	else if (!ft_strncmp(split_line[0], "pl", ft_strlen(split_line[0])))
		return (add_plane(display, split_line));
	else if (!ft_strncmp(split_line[0], "cy", ft_strlen(split_line[0])))
		return (add_cylinder(display, split_line));
	else if (!ft_strncmp(split_line[0], "co", ft_strlen(split_line[0])))
		return (add_cone(display, split_line));
	else
	{
		ft_putstr_fd("Error : Object not found\t", 2);
		return (1);
	}
}

static int	parse_line(t_disp *display, char *line, const size_t n)
{
	char	**split_line;
	int		ret;

	ret = 0;
	split_line = ft_split(line, ' ');
	if (!split_line)
	{
		perror("split");
		return (1);
	}
	if (ft_strlen_char_tab(split_line))
		ret = add_obj(display, split_line);
	if (ret)
		print_error_obj(n);
	ft_free_char_tab(split_line);
	return (ret);
}

static int	set_error(int ret, t_disp *display)
{
	if (!ret && (!display->cam.is_set || !display->llight
			|| !display->amb.is_set))
	{
		ft_putstr_fd("Error: You shall have one camera, ambient light and"
			" at least one light.\n", 2);
		ret = 1;
	}
	if (ret)
	{
		lobj_free(&display->lobj);
		lobj_free(&display->llight);
	}
	return (ret);
}

int	parser(t_disp *display, char *filename)
{
	char	*line;
	int		fd;
	int		ret;
	size_t	n;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (1);
	}
	ret = 0;
	line = get_next_line(fd);
	n = 1;
	while (line)
	{
		if (!ret && line[0] && parse_line(display, line, n))
			ret = 1;
		free(line);
		line = get_next_line(fd);
		n++;
	}
	free(line);
	return (set_error(ret, display));
}
