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

void	fill_point(t_pt *pt, double x, double y, double z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

void	fill_color(int *c_sc, int *c_dest)
{
	c_dest[0] = c_sc[0];
	c_dest[1] = c_sc[1];
	c_dest[2] = c_sc[2];
}

t_vect	fill_vector(double x, double y, double z)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

int	init_pix(t_ray *ray, double t, t_vect norm, int color[3])
{
	if (t > 0 && t < ray->pix.t)
	{
		ray->pix.active = 1;
		ray->pix.t = t;
		ray->pix.pt = op_add(ray->o, op_multf(t, ray->v));
		if (dot(ray->v, get_normalize(norm)) > 0)
			ray->pix.norm = get_normalize(op_multf(-1, norm));
		else
			ray->pix.norm = get_normalize(norm);
		fill_color(color, ray->pix.color);
		return (1);
	}
	return (0);
}
