/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkrajcov <vkrajcov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:18:26 by vkrajcov          #+#    #+#             */
/*   Updated: 2022/08/02 09:15:00 by vkrajcov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_co	copy_cone(t_co *cone)
{
	t_co	copy;

	copy.o = cone->o;
	copy.v = cone->v;
	copy.h = cone->h;
	copy.r = cone->r;
	copy.color[0] = cone->color[0];
	copy.color[1] = cone->color[1];
	copy.color[2] = cone->color[2];
	return (copy);
}

double	find_solution(t_ray *rc, double b, double d, double a)
{
	double	t[2];
	int		i;

	if ((-b - d) / (2 * a) < (-b + d) / (2 * a))
	{
		t[0] = (-b - d) / (2 * a);
		t[1] = (-b + d) / (2 * a);
	}
	else
	{
		t[0] = (-b + d) / (2 * a);
		t[1] = (-b - d) / (2 * a);
	}
	i = -1;
	while (++i < 2)
	{
		if (t[i] < 0)
			continue ;
		if (rc->o.y + rc->v.y * t[i] > 0)
			continue ;
		return (t[i]);
	}
	return (0);
}

t_vect	get_normal_cone(t_ray *rc, t_co *co, double t)
{
	double	inter_proj_axis;
	t_vect	inter;
	t_vect	h_norm;

	inter = op_add(rc->o, op_multf(t, rc->v));
	inter_proj_axis = length(op_subs(co->o, inter))
		* sqrt(1 + co->r / co->h * co->r / co->h);
	h_norm = op_add(co->o, op_multf(-inter_proj_axis, co->v));
	return (op_subs(inter, h_norm));
}
