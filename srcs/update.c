/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:22:45 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/18 15:12:57 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			on_loop_move(t_frame *f)
{
	if (f->keys[KEY_W] || f->keys[KEY_UP])
	{
		if (!f->map[(int)(f->pos->x + f->dir->x)][(int)f->pos->y])
			f->pos->x += f->dir->x * SPEED;
		if (!f->map[(int)f->pos->x][(int)(f->pos->y + f->dir->y)])
			f->pos->y += f->dir->y * SPEED;
	}
	if (f->keys[KEY_S] || f->keys[KEY_DOWN])
	{
		if (!f->map[(int)(f->pos->x - f->dir->x)][(int)f->pos->y])
			f->pos->x -= f->dir->x * SPEED;
		if (!f->map[(int)f->pos->x][(int)(f->pos->y - f->dir->y)])
			f->pos->y -= f->dir->y * SPEED;
	}
}

void			draw_to_img(t_frame *frame, int x, int y, int color)
{
	int i;

	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		i = (x * (frame->clr_depth / 8)) + (y * frame->addr_size);
		frame->addr[i] = color;
		frame->addr[++i] = color >> 8;
		frame->addr[++i] = color >> 16;
	}
}

void			refresh(t_frame *frame)
{
	draw_frame(frame);
	mlx_put_image_to_window(frame->mlx, frame->win, frame->img, 0, 0);
	mlx_destroy_image(frame->mlx, frame->img);
	init_img(frame);
}
