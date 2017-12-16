/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:10:38 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/12 23:14:46 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

/*
**	t_vect3d *ft_cross(t_vect3d *a, t_vect3d *b)
**	Finds the cross product of vectors a and b and returns the vector.
*/

t_vect3d	*ft_cross(t_vect3d *a, t_vect3d *b)
{
	t_vect3d *out;

	out = init_3d(0, 0, 0);
	out->x = (a->y * b->z) - (a->z * b->y);
	out->y = (a->z * b->x) - (a->x * b->z);
	out->z = (a->x * b->y) - (a->y * b->x);
	return (out);
}

/*
**	t_vect2d *ft_ortho(t_vect3d *a, char axis)
**	Projects the 3D vector a onto the 2D plane and returns the resulting
**	2D vector.
**	Axis variable specifies which axis the vector is projected from.
*/

t_vect2d	*ft_ortho(t_vect3d *a, char axis)
{
	t_vect2d *out;

	out = init_2d(0, 0);
	if (axis == 'x' || axis == 'X')
	{
		out->x = a->y;
		out->y = a->z;
	}
	else if (axis == 'y' || axis == 'Y')
	{
		out->x = a->x;
		out->y = a->z;
	}
	else
	{
		out->x = a->x;
		out->y = a->y;
	}
	return (out);
}

void		ft_transmat(double mat[4][4], t_vect3d *offset)
{
	double t[4][4];
	double result[4][4];

	ft_identity(t);
	t[3][0] = offset->x;
	t[3][1] = offset->y;
	t[3][2] = offset->z;
	ft_matmult(mat, t, result);
	ft_matcpy(result, mat);
}

void		ft_scalemat(double mat[4][4], t_vect3d *scale)
{
	double s[4][4];
	double result[4][4];

	ft_identity(s);
	s[0][0] = scale->x;
	s[1][1] = scale->y;
	s[2][2] = scale->z;
	ft_matmult(mat, s, result);
	ft_matcpy(result, mat);
}

void		ft_rotmat(double mat[4][4], t_vect3d *rot)
{
	double x[4][4];
	double y[4][4];
	double z[4][4];
	double ymat[4][4];
	double xymat[4][4];

	ft_identity(x);
	ft_identity(y);
	ft_identity(z);
	x[1][1] = cos(rot->x);
	x[1][2] = sin(rot->x);
	x[2][1] = -x[1][2];
	x[2][2] = x[1][1];
	y[0][0] = cos(rot->y);
	y[2][0] = sin(rot->y);
	y[0][2] = -y[2][0];
	y[2][2] = y[0][0];
	z[0][0] = cos(rot->z);
	z[0][1] = sin(rot->z);
	z[1][0] = -z[0][1];
	z[1][1] = z[0][0];
	ft_matmult(mat, y, ymat);
	ft_matmult(ymat, x, xymat);
	ft_matmult(xymat, z, mat);
}
