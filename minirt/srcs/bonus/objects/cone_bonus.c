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
#include "libft.h"
#include <math.h>

static double	co_inter_body(t_ray *rc, t_co *co)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;

	a = rc->v.x * rc->v.x + rc->v.z * rc->v.z - rc->v.y * rc->v.y
		* co->r / co->h * co->r / co->h;
	b = 2 * (rc->o.x * rc->v.x + rc->o.z * rc->v.z - rc->o.y * rc->v.y
			* co->r / co->h * co->r / co->h);
	c = rc->o.x * rc->o.x + rc->o.z * rc->o.z - rc->o.y * rc->o.y
		* co->r / co->h * co->r / co->h;
	d = b * b - 4 * a * c;
	if (sqrt(d) < 0)
		return (0);
	d = sqrt(d);
	t = find_solution(rc, b, d, a);
	if (rc->o.y + rc->v.y * t < co->o.y - co->h)
		return (0);
	return (t);
}

int	co_inter(t_ray *rc, t_co *co)
{
	t_forward	forward;
	t_ray		rc_cpy;
	t_co		co_cpy;
	double		ret1;
	int			ret2;

	rc_cpy = copy_ray(rc);
	co_cpy = copy_cone(co);
	forward = get_forward(co_cpy.o, co_cpy.v, fill_vector(0, 0, 0),
			fill_vector(0, 1, 0));
	apply_forward(forward, &rc_cpy.o, &rc_cpy.v);
	apply_forward(forward, &co_cpy.o, &co_cpy.v);
	ret1 = co_inter_body(&rc_cpy, &co_cpy);
	ret1 = init_pix(rc, ret1, get_normal_cone(rc, co, ret1), co->color);
	rc_cpy = copy_ray(rc);
	ret2 = cir_inter(&rc_cpy, &co->cap);
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

static t_co	*init_cone(char **split_line)
{
	t_co	*cone;

	if (!is_input_valid(split_line))
		return (NULL);
	cone = malloc(sizeof(t_co));
	if (!cone)
		return (NULL);
	if (!init_pt(&cone->o, split_line[1])
		|| !init_pt(&cone->v, split_line[2])
		|| !init_color(cone->color, split_line[5]))
	{
		free(cone);
		return (NULL);
	}
	normalize(&cone->v);
	cone->r = ft_atoi_double(split_line[3]) / 2;
	cone->h = ft_atoi_double(split_line[4]);
	cone->cap = init_circle(cone->o, op_multf(-1, cone->v),
			cone->r, cone->color);
	cone->o = op_add(cone->o, op_multf(cone->h, cone->v));
	return (cone);
}

int	add_cone(t_disp *disp, char **split_line)
{
	t_co	*cone;

	cone = init_cone(split_line);
	if (!cone)
	{
		ft_putstr_fd("Error: Cannot create cone.\n", 2);
		return (1);
	}
	lobj_add_back(&disp->lobj, lobj_new((void *)cone, CO));
	return (0);
}
