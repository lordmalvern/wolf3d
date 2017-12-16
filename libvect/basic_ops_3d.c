/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:11:19 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/12 23:14:02 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

/*
**	t_vect3d ft_add3d(t_vect3d a, t_vect3d b)
**	Adds two 3D vectors together and returns the sum.
*/

t_vect3d	*ft_add3d(t_vect3d *a, t_vect3d *b)
{
	t_vect3d *out;

	out = init_3d(0, 0, 0);
	out->x = a->x + b->x;
	out->y = a->y + b->y;
	out->z = a->z + b->z;
	return (out);
}

/*
**	t_vect3d ft_sub3d(t_vect3d a, t_vect3d b)
**	Subtracts two 3D vectors together and returns the difference.
*/

t_vect3d	*ft_sub3d(t_vect3d *a, t_vect3d *b)
{
	t_vect3d *out;

	out = init_3d(0, 0, 0);
	out->x = a->x - b->x;
	out->y = a->y - b->y;
	out->z = a->z - b->z;
	return (out);
}

/*
**	t_vect3d ft_mult3d(t_vect3d a, double s)
**	Performs a scalar multiplication on a 3D vector and returns the product.
*/

t_vect3d	*ft_mult3d(t_vect3d *a, double s)
{
	t_vect3d *out;

	out = init_3d(0, 0, 0);
	out->x = s * a->x;
	out->y = s * a->y;
	out->z = s * a->z;
	return (out);
}

/*
**	double ft_mag3d(t_vect3d a)
**	Finds the magnitude (length) of a 3D vector a and returns it.
*/

double		ft_mag3d(t_vect3d *a)
{
	double pyth;

	pyth = (a->x * a->x) + (a->y * a->y) + (a->z * a->z);
	return (sqrt(pyth));
}

/*
**	double ft_dot3d(t_vect3d a, t_vect3d b)
**	Finds the dot product of two 3D vectors and returns the final scalar.
*/

double		ft_dot3d(t_vect3d *a, t_vect3d *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}
