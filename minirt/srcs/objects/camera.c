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

#include "libft.h"
#include "minirt.h"

static int	is_input_valid(char **split_line)
{	
	return (is_number_param_valid(4, split_line)
		&& is_coords_valid(split_line[1])
		&& is_normalized_vector(split_line[2])
		&& ft_positive_atoi(split_line[3]) >= 0
		&& ft_positive_atoi(split_line[3]) <= 180);
}

static t_vect	init_tmp(t_vect	forward)
{
	t_vect	tmp;

	tmp = fill_vector(0, 1, 0);
	if (forward.x == 0 && forward.z == 0)
	{
		if (forward.y == 1)
			tmp = fill_vector(0, 0, 1);
		else
			tmp = fill_vector(0, 0, -1);
	}
	return (tmp);
}

int	set_camera(t_disp *disp, char **split_line)
{
	if (disp->cam.is_set)
	{
		ft_putstr_fd("Error: You cannot have two cameras.\t", 2);
		return (1);
	}
	if (!is_input_valid(split_line)
		|| !init_pt(&disp->cam.o, split_line[1])
		|| !init_pt(&disp->cam.forward, split_line[2]))
	{
		ft_putstr_fd("Error: Cannot create camera.\t", 2);
		return (1);
	}
	normalize(&disp->cam.forward);
	disp->cam.is_set = 1;
	disp->cam.fov = ft_positive_atoi(split_line[3]) * M_PI / 180;
	disp->cam.focal_len = ((double)WIDTH / 2) / tan(disp->cam.fov / 2);
	disp->cam.center = op_add(disp->cam.o,
			op_multf(disp->cam.focal_len, disp->cam.forward));
	disp->cam.right = get_normalize(cross(init_tmp(disp->cam.forward),
				disp->cam.forward));
	disp->cam.up = get_normalize(cross(disp->cam.forward, disp->cam.right));
	return (0);
}
