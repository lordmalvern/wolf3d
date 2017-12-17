/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:41:47 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/16 21:54:48 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			set_hooks(t_frame *frame)
{
	mlx_hook(frame->win, 2, 0, on_keypress, frame);
	mlx_hook(frame->win, 3, 0, on_keyrelease, frame);
	mlx_hook(frame->win, 17, 0, on_exit, frame);
	mlx_loop_hook(frame->mlx, on_loop, frame);
	mlx_expose_hook(frame->win, on_expose, frame);
}

void			set_palette(t_frame *frame)
{
}

t_frame			*init_frame(void)
{
	t_frame *frame;
	frame = malloc(sizeof(t_frame));
	frame->pos = init_2d(24, 15);
	frame->dir = init_2d(-1, 0);
	frame->plane = init_2d(0, .66);
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, WIDTH, HEIGHT, "Wolf3D");
	return (frame);
}
