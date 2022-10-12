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

double	cy_inter_body(t_ray *rc, t_cy *cy)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;

	a = (rc->v.x * rc->v.x + rc->v.z * rc->v.z);
	b = 2.0 * (rc->o.x * rc->v.x + rc->o.z * rc->v.z);
	c = (rc->o.x * rc->o.x + rc->o.z * rc->o.z - cy->r * cy->r);
	d = b * b - 4.0 * a * c;
	if (d < 0)
		return (0);
	d = sqrt(d);
	t = (-b - d) / (2.0 * a);
	if (t <= 0)
		t = (-b + d) / (2.0 * a);
	if (rc->o.y + rc->v.y * t < 0 || rc->o.y + rc->v.y * t > cy->h)
		return (0);
	return (t);
}

int	cy_inter(t_ray *rc, t_cy *cy)
{
	t_ray		rc_cpy;
	t_cy		cy_cpy;
	t_forward	forward;
	double		ret1;
	int			ret2;

	cy_cpy = copy_cylinder(cy);
	rc_cpy = copy_ray(rc);
	forward = get_forward(cy->o, cy->v, fill_vector(0, 0, 0),
			fill_vector(0, 1, 0));
	apply_forward(forward, &rc_cpy.o, &rc_cpy.v);
	apply_forward(forward, &cy_cpy.o, &cy_cpy.v);
	ret1 = cy_inter_body(&rc_cpy, &cy_cpy);
	ret1 = init_pix(rc, ret1, get_normal_cylinder(rc, cy, ret1), cy->color);
	rc_cpy = copy_ray(rc);
	ret2 = cir_inter(&rc_cpy, &cy_cpy.cap1);
	ret2 += cir_inter(&rc_cpy, &cy_cpy.cap2);
	if (ret2)
		rc->pix = rc_cpy.pix;
	return (ret1 || ret2);
}

static int	is_input_valid(char **split_line)
{	
	return (is_number_param_valid(6, split_line)
		&& is_coords_valid(split_line[1])
		&& is_normalized_vector(split_line[2])
		&& is_double_correct(split_line[3])
		&& ft_atoi_double(split_line[3]) != 0
		&& is_double_correct(split_line[4])
		&& ft_atoi_double(split_line[4]) != 0
		&& is_color_valid(split_line[5]));
}

static t_cy	*init_cylinder(char **split_line)
{
	t_cy	*cylinder;

	if (!is_input_valid(split_line))
		return (NULL);
	cylinder = malloc(sizeof(t_cy));
	if (!cylinder)
		return (NULL);
	if (!init_pt(&cylinder->o, split_line[1])
		|| !init_pt(&cylinder->v, split_line[2])
		|| !init_color(cylinder->color, split_line[5]))
	{
		free(cylinder);
		return (NULL);
	}
	normalize(&cylinder->v);
	cylinder->r = ft_atoi_double(split_line[3]) / 2;
	cylinder->h = ft_atoi_double(split_line[4]);
	cylinder->cap1 = init_circle(cylinder->o, op_multf(-1, cylinder->v),
			cylinder->r, cylinder->color);
	cylinder->cap2 = init_circle(op_add(cylinder->o, op_multf(cylinder->h,
					cylinder->v)), cylinder->v, cylinder->r, cylinder->color);
	normalize(&cylinder->cap1.pl.v);
	normalize(&cylinder->cap2.pl.v);
	return (cylinder);
}

int	add_cylinder(t_disp *disp, char **split_line)
{
	t_cy	*cylinder;

	cylinder = init_cylinder(split_line);
	if (!cylinder)
	{
		ft_putstr_fd("Error: Cannot create cylinder.\t", 2);
		return (1);
	}
	lobj_add_back(&disp->lobj, lobj_new((void *)cylinder, CYL));
	return (0);
}
