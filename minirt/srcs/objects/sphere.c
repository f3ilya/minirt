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

int	sph_inter(t_ray *rc, t_sph *sph)
{
	double	b;
	double	c;
	double	t1;
	double	t2;

	b = 2 * dot(rc->v, op_subs(rc->o, sph->o));
	c = get_norm2(op_subs(rc->o, sph->o)) - sph->r * sph->r;
	if (b * b - 4 * c < 0)
		return (0);
	t1 = (-b - sqrt(b * b - 4 * c)) / 2;
	t2 = (-b + sqrt(b * b - 4 * c)) / 2;
	if (t2 < 0)
		return (0);
	if (t1 > 0)
		return (init_pix(rc, t1, op_subs(op_add(rc->o,
						op_multf(t1, rc->v)), sph->o), sph->color));
	return (init_pix(rc, t2, op_subs(op_add(rc->o,
					op_multf(t2, rc->v)), sph->o), sph->color));
}

static int	is_input_valid(char **split_line)
{	
	return (is_number_param_valid(4, split_line)
		&& is_coords_valid(split_line[1])
		&& is_double_correct(split_line[2])
		&& ft_atoi_double(split_line[2]) != 0
		&& is_color_valid(split_line[3]));
}

static t_sph	*init_sphere(char **split_line)
{
	t_sph	*sphere;

	if (!is_input_valid(split_line))
		return (NULL);
	sphere = malloc(sizeof(t_sph));
	if (!sphere)
		return (NULL);
	if (!init_pt(&sphere->o, split_line[1]))
	{
		free(sphere);
		return (NULL);
	}
	sphere->r = ft_atoi_double(split_line[2]) / 2;
	if (!init_color(sphere->color, split_line[3]))
	{
		free(sphere);
		return (NULL);
	}
	return (sphere);
}

int	add_sphere(t_disp *disp, char **split_line)
{
	t_sph	*sphere;

	sphere = init_sphere(split_line);
	if (!sphere)
	{
		ft_putstr_fd("Error: Cannot create sphere.\t", 2);
		return (1);
	}
	lobj_add_back(&disp->lobj, lobj_new((void *)sphere, SPH));
	return (0);
}
