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

#ifndef STRUCT_H
# define STRUCT_H

typedef enum type{
	SPH,
	CYL,
	PL,
	LIGT,
	CO
}	t_type;

typedef struct s_vector{
	double		x;
	double		y;
	double		z;
}	t_vect;

typedef t_vect	t_pt;

typedef struct s_light{
	t_pt	o;
	double	w;
	int		color[3];

}	t_light;

typedef struct s_pixel{
	int		active;
	t_pt	pt;
	t_vect	norm;
	double	t;
	int		color[3];
	int		obj_id;
}	t_pix;

typedef struct s_ray{
	t_pt	o;
	t_vect	v;
	t_pix	pix;
}	t_ray;

typedef struct s_sphere
{
	t_pt	o;
	double	r;
	int		color[3];
}	t_sph;

typedef struct s_plane
{
	t_pt	o;
	t_vect	v;
	int		color[3];
}	t_pl;

typedef struct s_circle
{
	t_pl	pl;
	double	r;
}	t_cir;

typedef struct s_cylinder
{
	t_pt	o;
	t_vect	v;
	double	r;
	double	h;
	t_cir	cap1;
	t_cir	cap2;
	int		color[3];
}	t_cy;

typedef struct s_matrix
{
	t_vect	x;
	t_vect	y;
	t_vect	z;
}	t_matrix;

typedef struct s_forward
{
	t_vect		translation;
	t_matrix	rotation;
}	t_forward;

typedef struct s_ambient{
	int		is_set;
	double	w;
	int		color[3];
}	t_amb;

typedef struct s_camera{
	int		is_set;
	t_pt	o;
	double	fov;
	double	focal_len;
	t_vect	forward;
	t_vect	center;
	t_vect	right;
	t_vect	up;
}	t_cam;

typedef struct s_lobjet{
	void	*obj;
	char	type;
	void	*next;
}	t_lobj;

typedef struct s_image{
	void	*p;
	char	*img;
	int		bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_display{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		image;
	t_cam		cam;
	t_amb		amb;
	t_lobj		*lobj;
	t_lobj		*llight;
}	t_disp;

#endif