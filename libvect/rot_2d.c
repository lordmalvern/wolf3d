/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:21:33 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 13:28:29 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

void			ft_rot2d(t_vect2d *a, double theta)
{
	double old_x;

	old_x = a->x;
	a->x = a->x * cos(theta) - a->y * sin(theta);
	a->y = old_x * sin(theta) + a->y * cos(theta);
}
