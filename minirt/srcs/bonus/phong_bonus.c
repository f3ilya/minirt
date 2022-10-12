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

double	phong(t_light *l, t_ray *rc)
{
	t_vect	light_dir;
	t_vect	reflect;
	double	dot_pix_l;
	double	phong;
	double	lobe;

	phong = 0;
	light_dir = get_normalize(op_subs(l->o, rc->pix.pt));
	dot_pix_l = dot(rc->pix.norm, light_dir);
	if (dot_pix_l > 0)
	{
		reflect = op_subs(op_multf(2 * dot(rc->pix.norm, light_dir),
					rc->pix.norm), light_dir);
		lobe = dot(reflect, op_multf(-1, rc->v));
		if (lobe > 0)
			phong = powf(lobe, PHONG_R);
	}
	return (phong);
}
