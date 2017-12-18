/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:22:45 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 23:17:02 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			on_loop_move(t_frame *f)
{
	if (f->keys[KEY_W] || f->keys[KEY_UP])
	{
		if(!f->map[(int)(f->pos->x + f->dir->x)][(int)f->pos->y])
			f->pos->x += f->dir->x * SPEED;
		if(!f->map[(int)f->pos->x][(int)(f->pos->y + f->dir->y)])
			f->pos->y += f->dir->y * SPEED;
	}
	if (f->keys[KEY_S] || f->keys[KEY_DOWN])
	{
		if(!f->map[(int)(f->pos->x - f->dir->x)][(int)f->pos->y])
			f->pos->x -= f->dir->x * SPEED;
		if(!f->map[(int)f->pos->x][(int)(f->pos->y - f->dir->y)])
			f->pos->y -= f->dir->y * SPEED;
	}
}

void			refresh(t_frame *frame)
{
	mlx_clear_window (frame->mlx, frame->win);
	draw_frame(frame);
}
