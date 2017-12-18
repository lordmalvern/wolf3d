/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:41:47 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 21:11:53 by bpuschel         ###   ########.fr       */
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
	int x;
	int y;
	int xor;

	frame->tex = malloc(3 * sizeof(unsigned int **));
	frame->tex[0] = malloc(TEX * sizeof(unsigned int *));
	frame->tex[1] = malloc(TEX * sizeof(unsigned int *));
	frame->tex[2] = malloc(TEX * sizeof(unsigned int *));
	y = -1;
	while (++y < TEX)
	{
		frame->tex[0][y] = malloc(TEX * sizeof(unsigned int));
		frame->tex[1][y] = malloc(TEX * sizeof(unsigned int));
		frame->tex[2][y] = malloc(TEX * sizeof(unsigned int));
		x = -1;
		while (++x < TEX)
		{
			xor = (x * 256 / TEX) ^ (y * 256 / TEX);
			frame->tex[0][y][x] = xor + 256 * xor + 65536 * xor;
			frame->tex[1][y][x] = xor + 128 * xor;
			frame->tex[2][y][x] = xor + 32000 * xor;
		}
	}
}

t_frame			*init_frame(void)
{
	t_frame *frame;
	frame = malloc(sizeof(t_frame));
	frame->pos = init_2d(24, 15);
	frame->dir = init_2d(-1, 0);
	frame->plane = init_2d(0, .66);
	frame->r_dir = init_2d(0, 0);
	frame->dist = init_2d(0, 0);
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, WIDTH, HEIGHT, "Wolf3D");
	return (frame);
}
