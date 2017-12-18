/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:52:36 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/18 11:18:31 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				on_expose(t_frame *frame)
{
	refresh(frame);
	return (0);
}

int				on_loop(t_frame *frame)
{
	on_loop_move(frame);
	if (frame->keys[KEY_A] || frame->keys[KEY_LEFT])
	{
		ft_rot2d(frame->dir, ROT);
		ft_rot2d(frame->plane, ROT);
	}
	if (frame->keys[KEY_D] || frame->keys[KEY_RGHT])
	{
		ft_rot2d(frame->dir, -ROT);
		ft_rot2d(frame->plane, -ROT);
	}
	refresh(frame);
	return (0);
}

int				on_exit(t_frame *frame)
{
	mlx_destroy_window(frame->mlx, frame->win);
	exit(0);
}

int				on_keypress(int code, t_frame *frame)
{
	if (code == (int)KEY_ESC)
		exit(0);
	if (code < 127 && code >= 0)
		frame->keys[code] = 1;
	return (0);
}

int				on_keyrelease(int code, t_frame *frame)
{
	if (code < 127 && code >= 0)
		frame->keys[code] = 0;
	return (0);
}
