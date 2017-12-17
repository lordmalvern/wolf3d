/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:16:24 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/16 19:28:35 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/ft_printf.h"
# include "../libvect/libvect.h"
# include "../mlx/mlx.h"
# include "gfx_helper.h"

typedef struct	s_frame
{
	void			*mlx;
	void			*win;
	t_vect2d		*pos;
	t_vect2d		*dir;
	t_vect2d		*plane;
	int				height;
	int				width;
	unsigned int	*colors;
	int				**map;
	int				keys[127];

}				t_frame;

void			set_hooks(t_frame *frame);
void			set_palette(t_frame *frame);
t_frame			*init_frame(void);
void			refresh(t_frame *frame);
void			draw_pixel(t_frame *frame, double x, double y);
void			cast_rays(t_frame *frame);
void			draw_frame(t_frame *frame);
void			parse_map(t_frame *frame, char *file);
int				on_expose(t_frame *frame);
int				on_loop(t_frame *frame);
int				on_exit(t_frame *frame);
int				on_keypress(int code, t_frame *frame);
int				on_keyrelease(int code, t_frame *frame);
#endif
