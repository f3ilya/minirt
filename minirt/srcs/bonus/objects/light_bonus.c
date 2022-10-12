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

#include "bonus.h"

static int	is_input_valid(char **split_line)
{
	return (is_number_param_valid(4, split_line)
		&& is_coords_valid(split_line[1])
		&& is_double_correct(split_line[2])
		&& ft_atoi_double(split_line[2]) >= 0
		&& ft_atoi_double(split_line[2]) <= 1
		&& is_color_valid(split_line[3]));
}

static int	is_input_valid_without_color(char **split_line)
{
	return (is_number_param_valid(3, split_line)
		&& is_coords_valid(split_line[1])
		&& is_double_correct(split_line[2])
		&& ft_atoi_double(split_line[2]) >= 0
		&& ft_atoi_double(split_line[2]) <= 1);
}

static t_light	*init_light(char **split_line)
{
	t_light	*light;

	if (!is_input_valid(split_line))
		if (!is_input_valid_without_color(split_line))
			return (NULL);
	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	if (!init_pt(&light->o, split_line[1]))
	{
		free(light);
		return (NULL);
	}
	light->w = ft_atoi_double(split_line[2]);
	if (ft_strlen_char_tab(split_line) == 3)
	{
		fill_color((int []){255, 255, 255}, light->color);
		return (light);
	}
	if (!init_color(light->color, split_line[3]))
	{
		free(light);
		return (NULL);
	}
	return (light);
}

int	add_light(t_disp *disp, char **split_line)
{
	t_light	*light;

	light = init_light(split_line);
	if (!light)
	{
		ft_putstr_fd("Error: Cannot create light.\t", 2);
		return (1);
	}
	lobj_add_back(&disp->llight, lobj_new(light, LIGT));
	return (0);
}
