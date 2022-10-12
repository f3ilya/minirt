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

#ifndef MINIRT_H
# define MINIRT_H

# include "struct.h"
# include "../MinilibX/sierra/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define HEIGHT 1000
# define WIDTH 1000

/////////////////*----------display----------*///////////////
/*------display------*/
int			display(t_disp *disp);

/*-----img_actualisation----*/
int			hexcolor(int r, int g, int b);
int			pix_actualisation_img(t_disp *disp, int x, int y, int color);

/////////////////*-----------utils-----------*///////////////

/*-----fts_fill-----*/
void		fill_point(t_pt *pt, double x, double y, double z);
void		fill_color(int *c_sc, int *c_dest);
t_vect		fill_vector(double x, double y, double z);
int			init_pix(t_ray *ray, double t, t_vect norm, int color[3]);

/*-----fts_frees-----*/
int			free_display_and_exit(t_disp *disp);
int			keys_actions(int keycode, t_disp *disp);

/*-----fts_lst-----*/
t_lobj		*lobj_new(void *obj, int type);
void		lobj_free(t_lobj **lobj);
void		lobj_add_back(t_lobj **alst, t_lobj *new);

/*-----fts_vect_op1-----*/
double		dot(t_vect v1, t_vect v2);
double		get_norm2(t_vect vect);
void		normalize(t_vect *vect);
t_vect		get_normalize(t_vect vect);
t_vect		cross(t_vect a, t_vect b);
double		length(t_vect a);

/*-----fts_vect_op2-----*/
t_vect		op_add(t_vect v1, t_vect v2);
t_vect		op_subs(t_vect v1, t_vect v2);
t_vect		op_multf(double a, t_vect v);
t_vect		op_divv(t_vect v1, t_vect v2);

/*-----matrix-----*/
t_matrix	init_matrix(t_vect x, t_vect y, t_vect z);
t_vect		mult_mat_vect(t_matrix matrix, t_vect vect);

/*-----translation_rotation-----*/
t_forward	get_forward(t_pt from_o, t_vect from_v, t_pt to_o, t_vect to_v);
void		apply_forward(t_forward forward, t_pt *o, t_vect *v);
t_ray		copy_ray(t_ray	*ray);

/*-----cylinder_utils-----*/
t_vect		get_normal_cylinder(t_ray *rc, t_cy *cy, double t);
t_cy		copy_cylinder(t_cy *cy);

/////////////////*----------objects-----------*//////////////

/*-----sphere.c-----*/
int			add_sphere(t_disp *display, char **split_line);
int			sph_inter(t_ray *rc, t_sph *sph);

/*------plane.c-----*/
int			add_plane(t_disp *display, char **split_line);
int			pl_inter(t_ray *rc, t_pl *plane);

/*-----cylinder.c-----*/
int			cy_inter(t_ray *rc, t_cy *cy);
int			add_cylinder(t_disp *display, char **split_line);
int			intersection_cylinder(t_ray *rc);

/*-----circle-----*/
t_cir		init_circle(t_pt o, t_vect v, double r, int color[3]);
int			cir_inter(t_ray *rc, t_cir *cir);

/*-----ambient.c-----*/
int			set_ambient(t_disp *disp, char **split_line);

/*-----camera.c-----*/
int			set_camera(t_disp *disp, char **split_line);

/*-------light.c-------*/
int			add_light(t_disp *disp, char **split_line);

/*-----init_params-----*/
t_pt		*init_pt(t_pt *point, char *input);
int			*init_color(int color[3], char *input);

//////////////////*----------parser-----------*//////////////////

/*-----checker.c-----*/
int			is_number_param_valid(int expected, char **params);
int			is_double_correct(const char *nb);
int			is_coords_valid(char *to_split);
int			is_color_valid(char *to_split);
int			is_normalized_vector(char *to_split);

/*-----get_next_line.c-----*/
char		*get_next_line(int fd);

/*-----parser.c-----*/
int			parser(t_disp *display, char *filename);

#endif
