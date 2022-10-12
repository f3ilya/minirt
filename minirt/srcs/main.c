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

void	make_env(t_disp *disp)
{
	disp->lobj = NULL;
	disp->llight = NULL;
	disp->amb.is_set = 0;
	disp->cam.is_set = 0;
}

static int	free_display(t_disp *disp)
{
	if (disp->mlx_ptr)
	{
		if (disp->image.p)
			mlx_destroy_image(disp->mlx_ptr, disp->image.p);
		if (disp->win_ptr)
			mlx_destroy_window(disp->mlx_ptr, disp->win_ptr);
		free(disp->mlx_ptr);
	}
	return (1);
}

int	init_disp(t_disp *disp)
{
	disp->win_ptr = NULL;
	disp->image.p = NULL;
	disp->image.img = NULL;
	disp->mlx_ptr = mlx_init();
	if (!disp->mlx_ptr)
		return (1);
	disp->win_ptr = mlx_new_window(disp->mlx_ptr, WIDTH, HEIGHT, "MiniRT");
	if (!disp->win_ptr)
		return (free_display(disp));
	disp->image.p = mlx_new_image(disp->mlx_ptr, WIDTH, HEIGHT);
	if (!disp->image.p)
		return (free_display(disp));
	disp->image.img = mlx_get_data_addr(disp->image.p, &disp->image.bits, \
		&disp->image.size_line, &disp->image.endian);
	if (!disp->image.img)
		return (free_display(disp));
	return (0);
}

int	main(int ac, char **av)
{
	t_disp	disp;

	if (ac != 2 || ft_strncmp(&av[1][ft_strlen(av[1]) - 3], ".rt", 3))
	{
		ft_putstr_fd("Error: Bad usage: ./miniRT <file.rt>.\n", 2);
		return (2);
	}
	make_env(&disp);
	if (parser(&disp, av[1]))
		return (1);
	if (init_disp(&disp))
	{
		lobj_free(&disp.lobj);
		lobj_free(&disp.llight);
		return (1);
	}
	display(&disp);
	mlx_put_image_to_window(disp.mlx_ptr, disp.win_ptr, disp.image.p, 0, 0);
	mlx_hook(disp.win_ptr, 17, 0, free_display_and_exit, &disp);
	mlx_key_hook(disp.win_ptr, keys_actions, &disp);
	mlx_loop(disp.mlx_ptr);
	return (0);
}
