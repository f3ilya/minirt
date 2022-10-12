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

static t_pt	translate(t_vect trans_vect, t_pt from)
{
	t_pt	ret;

	ret.x = from.x + trans_vect.x;
	ret.y = from.y + trans_vect.y;
	ret.z = from.z + trans_vect.z;
	return (ret);
}

static t_matrix	get_rotation_matrix(t_vect from, t_vect to)
{
	t_vect	v;
	double	c;
	double	k;

	v = cross(from, to);
	c = dot(from, to);
	if (c == -1)
		return (init_matrix(
				fill_vector(1, 0, 0),
				fill_vector(0, -1, 0),
				fill_vector(0, 0, 1)));
	k = 1.0 / (1.0 + c);
	return (init_matrix(
			fill_vector(v.x * v.x * k + c, v.y * v.x * k - v.z,
				v.z * v.x * k + v.y),
			fill_vector(v.x * v.y * k + v.z, v.y * v.y * k + c,
				v.z * v.y * k - v.x),
			fill_vector(v.x * v.z * k - v.y, v.y * v.z * k + v.x,
				v.z * v.z * k + c)));
}

t_forward	get_forward(t_pt from_o, t_vect from_v, t_pt to_o, t_vect to_v)
{
	t_forward	forward;

	forward.rotation = get_rotation_matrix(from_v, to_v);
	from_o = mult_mat_vect(forward.rotation, from_o);
	forward.translation = op_subs(to_o, from_o);
	return (forward);
}

void	apply_forward(t_forward forward, t_pt *o, t_vect *v)
{
	*o = mult_mat_vect(forward.rotation, *o);
	*o = translate(forward.translation, *o);
	*v = get_normalize(mult_mat_vect(forward.rotation, *v));
}

t_ray	copy_ray(t_ray	*ray)
{
	t_ray	copy;

	copy.o = ray->o;
	copy.v = ray->v;
	copy.pix = ray->pix;
	return (copy);
}
