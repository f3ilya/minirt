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

int	free_display_and_exit(t_disp *disp)
{
	mlx_destroy_image(disp->mlx_ptr, disp->image.p);
	mlx_destroy_window(disp->mlx_ptr, disp->win_ptr);
	lobj_free(&disp->lobj);
	lobj_free(&disp->llight);
	free(disp->mlx_ptr);
	exit(0);
	return (0);
}

int	keys_actions(int keycode, t_disp *disp)
{
	if (keycode == 65307)
		free_display_and_exit(disp);
	return (0);
}
