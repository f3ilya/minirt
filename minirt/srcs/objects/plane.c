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

int	pl_inter(t_ray *ray, t_pl *pl)
{
	double	d;
	double	t;
	t_vect	origins;

	d = dot(pl->v, ray->v);
	if (fabs(d) > 0.0001)
	{
		origins = op_subs(pl->o, ray->o);
		t = dot(origins, pl->v) / d;
		return (init_pix(ray, t, pl->v, pl->color));
	}
	return (0);
}

static int	is_input_valid(char **split_line)
{	
	return (is_number_param_valid(4, split_line)
		&& is_coords_valid(split_line[1])
		&& is_normalized_vector(split_line[2])
		&& is_color_valid(split_line[3]));
}

static t_pl	*init_plane(char **split_line)
{
	t_pl	*plane;

	if (!is_input_valid(split_line))
		return (NULL);
	plane = malloc(sizeof(t_pl));
	if (!plane)
		return (NULL);
	if (!init_pt(&plane->o, split_line[1]))
	{
		free(plane);
		return (NULL);
	}
	if (!init_pt(&plane->v, split_line[2]))
	{
		free(plane);
		return (NULL);
	}
	normalize(&plane->v);
	if (!init_color(plane->color, split_line[3]))
	{
		free(plane);
		return (NULL);
	}
	return (plane);
}

int	add_plane(t_disp *disp, char **split_line)
{
	t_pl	*plane;

	plane = init_plane(split_line);
	if (!plane)
	{
		ft_putstr_fd("Error: Cannot create plane.\t", 2);
		return (1);
	}
	ft_lstadd_back((t_list **)&disp->lobj,
		(t_list *)lobj_new((void *)plane, PL));
	return (0);
}
