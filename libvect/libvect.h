/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <bpuschel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:45:59 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 13:29:13 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H
# include <math.h>
# include <stdlib.h>

typedef struct	s_vect2d
{
	double x;
	double y;
}				t_vect2d;
typedef struct	s_vect3d
{
	double x;
	double y;
	double z;
}				t_vect3d;

t_vect2d		*ft_add2d(t_vect2d *a, t_vect2d *b);
t_vect2d		*ft_sub2d(t_vect2d *a, t_vect2d *b);
t_vect2d		*ft_mult2d(t_vect2d *a, double s);
double			ft_mag2d(t_vect2d *a);
double			ft_dot2d(t_vect2d *a, t_vect2d *b);
t_vect3d		*ft_add3d(t_vect3d *a, t_vect3d *b);
t_vect3d		*ft_sub3d(t_vect3d *a, t_vect3d *b);
t_vect3d		*ft_mult3d(t_vect3d *a, double s);
double			ft_mag3d(t_vect3d *a);
double			ft_dot3d(t_vect3d *a, t_vect3d *b);
t_vect3d		*ft_cross(t_vect3d *a, t_vect3d *b);
t_vect2d		*ft_ortho(t_vect3d *a, char axis);
t_vect2d		*init_2d(double x, double y);
t_vect3d		*init_3d(double x, double y, double z);
void			init_mat(double mat[4][4]);
void			ft_matcpy(double src[4][4], double dst[4][4]);
void			ft_matmult(double a[4][4], double b[4][4], double dst[4][4]);
t_vect3d		*ft_sqandcol(double mat[4][4], t_vect3d *v, t_vect3d *out);
void			ft_identity(double mat[4][4]);
void			ft_transmat(double mat[4][4], t_vect3d *offset);
void			ft_scalemat(double mat[4][4], t_vect3d *scale);
void			ft_rotmat(double mat[4][4], t_vect3d *rot);
void			ft_rot2d(t_vect2d *a, double theta);
#endif
