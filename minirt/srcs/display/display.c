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

int	light_inter(t_disp *disp, t_light *l, t_pix pix)
{
	t_ray	rl;
	t_lobj	*obj;

	rl.o = op_add(pix.pt, op_multf(0.01, pix.norm));
	rl.v = get_normalize(op_subs(l->o, pix.pt));
	obj = disp->lobj;
	while (obj)
	{
		rl.pix.t = INFINITY;
		if (obj->type == SPH && sph_inter(&rl, (t_sph *)obj->obj)
			&& rl.pix.t * rl.pix.t < get_norm2(op_subs(l->o, pix.pt)))
			return (1);
		else if (obj->type == PL && pl_inter(&rl, (t_pl *)obj->obj)
			&& rl.pix.t * rl.pix.t < get_norm2(op_subs(l->o, pix.pt)))
			return (1);
		else if (obj->type == CYL && cy_inter(&rl, (t_cy *)obj->obj)
			&& rl.pix.t * rl.pix.t < get_norm2(op_subs(l->o, pix.pt)))
			return (1);
		obj = obj->next;
	}
	return (0);
}

static void	f_mult_color(double a, int *color, int *color_src)
{
	color[0] = a * (double)color_src[0];
	color[1] = a * (double)color_src[1];
	color[2] = a * (double)color_src[2];
}

int	color_def(t_disp *disp, t_pix pix)
{
	double	wpix;
	t_lobj	*light;
	t_light	*l;
	int		color[3];

	light = disp->llight;
	f_mult_color(disp->amb.w, color, disp->amb.color);
	l = (t_light *)light->obj;
	if (!light_inter(disp, l, pix))
		wpix = fmax(0., l->w * dot(get_normalize(\
			op_subs(l->o, pix.pt)), pix.norm))
			/ powf(get_norm2(op_subs(l->o, pix.pt)), 0.25);
	else
		wpix = 0;
	color[0] = fmin(255., (wpix * (double)l->color[0] + color[0])
			* (double)pix.color[0] / 255.);
	color[1] = fmin(255., (wpix * (double)l->color[1] + color[1])
			* (double)pix.color[1] / 255.);
	color[2] = fmin(255., (wpix * (double)l->color[2] + color[2])
			* (double)pix.color[2] / 255.);
	return (hexcolor(color[0], color[1], color[2]));
}

void	objs_inter(t_disp *disp, t_ray *rc, int x, int y)
{
	t_lobj	*obj;

	obj = disp->lobj;
	rc->pix.t = INFINITY;
	rc->pix.active = 0;
	while (obj)
	{
		if (obj->type == SPH)
			sph_inter(rc, (t_sph *)obj->obj);
		else if (obj->type == PL)
			pl_inter(rc, (t_pl *)obj->obj);
		else
			cy_inter(rc, (t_cy *)obj->obj);
		obj = obj->next;
	}
	if (rc->pix.active)
		pix_actualisation_img(disp, x, HEIGHT - y - 1,
			color_def(disp, rc->pix));
}

int	display(t_disp *disp)
{
	int		x;
	int		y;
	t_ray	rc;
	t_pt	pos_screen;

	y = -1;
	rc.o = disp->cam.o;
	while (++ y < HEIGHT)
	{	
		x = -1;
		while (++ x < WIDTH)
		{
			pos_screen = op_add(op_add(disp->cam.center,
						op_multf((x - WIDTH / 2), disp->cam.right)),
					op_multf((y - HEIGHT / 2), disp->cam.up));
			rc.v = op_add(pos_screen, op_multf(-1, disp->cam.o));
			normalize(&rc.v);
			objs_inter(disp, &rc, x, y);
		}
	}
	return (0);
}
