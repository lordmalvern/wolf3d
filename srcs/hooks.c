/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:52:36 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/16 20:30:32 by bpuschel         ###   ########.fr       */
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
}

int				on_exit(t_frame *frame)
{
	mlx_destroy_window(frame->mlx, frame->win);
	exit (0);
}

int				on_keypress(int code, t_frame *frame)
{
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
