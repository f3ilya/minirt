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

t_matrix	init_matrix(t_vect x, t_vect y, t_vect z)
{
	t_matrix	matrix;

	matrix.x = x;
	matrix.y = y;
	matrix.z = z;
	return (matrix);
}

t_vect	mult_mat_vect(t_matrix matrix, t_vect vect)
{
	t_vect	ret;

	ret.x = matrix.x.x * vect.x + matrix.x.y * vect.y + matrix.x.z * vect.z;
	ret.y = matrix.y.x * vect.x + matrix.y.y * vect.y + matrix.y.z * vect.z;
	ret.z = matrix.z.x * vect.x + matrix.z.y * vect.y + matrix.z.z * vect.z;
	return (ret);
}
