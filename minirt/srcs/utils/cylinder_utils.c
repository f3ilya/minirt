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

#include "minirt.h"

t_vect	get_normal_cylinder(t_ray *rc, t_cy *cy, double t)
{
	double	d;
	t_vect	inter;
	t_vect	h_norm;

	inter = op_add(rc->o, op_multf(t, rc->v));
	d = dot(cy->v, op_subs(inter, cy->o));
	h_norm = op_add(cy->o, op_multf(d, cy->v));
	return (op_subs(inter, h_norm));
}

t_cy	copy_cylinder(t_cy *cy)
{
	t_cy	cy_cpy;

	cy_cpy.o = cy->o;
	cy_cpy.v = cy->v;
	cy_cpy.h = cy->h;
	cy_cpy.r = cy->r;
	cy_cpy.color[0] = cy->color[0];
	cy_cpy.color[1] = cy->color[1];
	cy_cpy.color[2] = cy->color[2];
	cy_cpy.cap1 = cy->cap1;
	cy_cpy.cap2 = cy->cap2;
	return (cy_cpy);
}
