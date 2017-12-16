/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:45:29 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/12 23:14:33 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

void		ft_matcpy(double src[4][4], double dst[4][4])
{
	dst[0][0] = src[0][0];
	dst[0][1] = src[0][1];
	dst[0][2] = src[0][2];
	dst[0][3] = src[0][3];
	dst[1][0] = src[1][0];
	dst[1][1] = src[1][1];
	dst[1][2] = src[1][2];
	dst[1][3] = src[1][3];
	dst[2][0] = src[2][0];
	dst[2][1] = src[2][1];
	dst[2][2] = src[2][2];
	dst[2][3] = src[2][3];
	dst[3][0] = src[3][0];
	dst[3][1] = src[3][1];
	dst[3][2] = src[3][2];
	dst[3][3] = src[3][3];
}

void		ft_matmult(double a[4][4], double b[4][4], double dst[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			dst[i][j] = a[i][0] * b[0][j];
			dst[i][j] += a[i][1] * b[1][j];
			dst[i][j] += a[i][2] * b[2][j];
			dst[i][j] += a[i][3] * b[3][j];
		}
	}
}

t_vect3d	*ft_sqandcol(double mat[4][4], t_vect3d *v, t_vect3d *out)
{
	out->x = v->x * mat[0][0] + v->y * mat[1][0] + v->z * mat[2][0] + mat[3][0];
	out->y = v->x * mat[0][1] + v->y * mat[1][1] + v->z * mat[2][1] + mat[3][1];
	out->z = v->x * mat[0][2] + v->y * mat[1][2] + v->z * mat[2][2] + mat[3][2];
	return (out);
}

void		ft_identity(double mat[4][4])
{
	init_mat(mat);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}
