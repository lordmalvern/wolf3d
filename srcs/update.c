/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 12:22:45 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 13:54:16 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			on_loop_move(t_frame *frame)
{
	if (frame->keys[KEY_W] || frame->keys[KEY_UP])
	{
		if(!frame->map[frame->pos->x + frame->dir->x][frame->pos->y])
			frame->pos->x += frame->dir->x;
		if(!frame->map[frame->pos->x][frame->pos->y + frame->pos->y])
			frame->pos->y += frame->dir->y;
	}
	if (frame->keys[KEY_S] || frame->keys[KEY_DOWN])
	{
		if(!frame->map[frame->pos->x - frame->dir->x][frame->pos->y])
			frame->pos->x -= frame->dir->x;
		if(!frame->map[frame->pos->x][frame->pos->y - frame->pos->y])
			frame->pos->y -= frame->dir->y;
	}
}

void			refresh(t_frame *frame)
{
}
