/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:28:49 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/12 23:14:21 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect2d	*init_2d(double x, double y)
{
	t_vect2d *out;

	out = (t_vect2d*)malloc(sizeof(t_vect2d));
	out->x = x;
	out->y = y;
	return (out);
}

t_vect3d	*init_3d(double x, double y, double z)
{
	t_vect3d *out;

	out = (t_vect3d*)malloc(sizeof(t_vect3d));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

void		init_mat(double mat[4][4])
{
	mat[0][0] = 0;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 0;
	mat[1][0] = 0;
	mat[1][1] = 0;
	mat[1][2] = 0;
	mat[1][3] = 0;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 0;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 0;
}
