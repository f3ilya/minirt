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

int	test_pix_in_wind(int x, int y)
{
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return (0);
	return (1);
}

int	hexcolor(int r, int g, int b)
{
	return (b + g * 256 + r * 256 * 256);
}

int	pix_actualisation_img(t_disp *disp, int x, int y, int color)
{
	int	pixel;

	if (test_pix_in_wind(x, y))
	{
		pixel = (y * disp->image.size_line) + (x * disp->image.bits / 8);
		if (disp->image.endian == 1)
		{
			disp->image.img[pixel + 0] = color >> 24;
			disp->image.img[pixel + 1] = (color >> 16) & 0xFF;
			disp->image.img[pixel + 2] = (color >> 8) & 0xFF;
			disp->image.img[pixel + 3] = color & 0xFF;
			return (1);
		}
		else if (disp->image.endian == 0)
		{
			disp->image.img[pixel + 0] = color & 0xFF;
			disp->image.img[pixel + 1] = (color >> 8) & 0xFF;
			disp->image.img[pixel + 2] = (color >> 16) & 0xFF;
			disp->image.img[pixel + 3] = color >> 24;
			return (1);
		}
	}
	return (0);
}
