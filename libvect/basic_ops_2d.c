/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <bpuschel@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:16:13 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/12 23:22:12 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

/*
**	t_vect2d ft_add2d(t_vect2d a, t_vect2d b)
**	Adds two 2D vectors and returns the sum.
*/

t_vect2d	*ft_add2d(t_vect2d *a, t_vect2d *b)
{
	t_vect2d *out;

	out = init_2d(0, 0);
	out->x = a->x + b->x;
	out->y = a->y + b->y;
	return (out);
}

/*
**	t_vect2d ft_sub2d(t_vect2d a, t_vect2d b)
**	Subtracts two 2D vectors and returns the difference.
*/

t_vect2d	*ft_sub2d(t_vect2d *a, t_vect2d *b)
{
	t_vect2d *out;

	out = init_2d(0, 0);
	out->x = a->x - b->x;
	out->y = a->y - b->y;
	return (out);
}

/*
**	t_vect2d ft_mult2d(t_vect2d a, double s)
**	Multiplies a 2D vector a by scalar s and returns the final vector.
*/

t_vect2d	*ft_mult2d(t_vect2d *a, double s)
{
	t_vect2d *out;

	out = init_2d(0, 0);
	out->x = (a->x == 0) ? 0 : a->x * s;
	out->y = (a->y == 0) ? 0 : a->y * s;
	return (out);
}

/*
**	double ft_mag2d(t_vect2d a)
**	Finds the magnitude (length) of vector a and returns it
*/

double		ft_mag2d(t_vect2d *a)
{
	double p;

	if (a->x == 0 && a->y == 0)
		return (0);
	else if (a->x == 0)
		p = (a->y * a->y);
	else if (a->y == 0)
		p = (a->x * a->x);
	else
		p = (a->x * a->x) + (a->y * a->y);
	return (sqrt(p));
}

/*
**	double ft_dot2d(t_vect2d a, t_vect2d b)
**	Calculates the dot product of 2D vectors a and b and returns the value.
*/

double		ft_dot2d(t_vect2d *a, t_vect2d *b)
{
	double p;

	if ((a->x == 0 && a->y == 0) || (b->x == 0 && b->y == 0))
		return (0);
	else if (a->x == 0 || b->x == 0)
		p = a->y * b->y;
	else if (a->y == 0 || b->y == 0)
		p = a->x * b->x;
	else
		p = (a->x * b->x) + (a->y * b->y);
	return (p);
}
