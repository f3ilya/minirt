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
#include "libft.h"
#include <math.h>

int	cir_inter(t_ray *rc, t_cir *cir)
{
	t_vect	v;

	if (pl_inter(rc, &cir->pl))
	{
		v = op_subs(rc->pix.pt, cir->pl.o);
		return (length(v) <= cir->r);
	}
	return (0);
}

t_cir	init_circle(t_pt o, t_vect v, double r, int color[3])
{
	t_cir	circle;

	circle.pl.o = o;
	circle.pl.v = v;
	circle.r = r;
	circle.pl.color[0] = color[0];
	circle.pl.color[1] = color[1];
	circle.pl.color[2] = color[2];
	return (circle);
}
