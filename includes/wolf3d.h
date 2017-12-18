/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 20:16:24 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/18 15:23:41 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/ft_printf.h"
# include "../libvect/libvect.h"
# include "../mlx/mlx.h"
# include "gfx_helper.h"
# define TEX 64
# define ROT 0.1
# define SPEED 0.1

typedef struct	s_frame
{
	void			*mlx;
	void			*win;
	void			*img;
	t_vect2d		*pos;
	t_vect2d		*dir;
	t_vect2d		*plane;
	t_vect2d		*r_dir;
	t_vect2d		*dist;
	int				height;
	int				width;
	int				side;
	int				is_wall;
	unsigned int	***tex;
	int				**map;
	char			*addr;
	int				clr_depth;
	int				addr_size;
	int				endian;
	int				keys[127];

}				t_frame;

void			set_hooks(t_frame *frame);
void			set_palette(t_frame *frame);
t_frame			*init_frame(void);
void			init_img(t_frame *frame);
void			draw_to_img(t_frame *frame, int x, int y, int color);
void			refresh(t_frame *frame);
void			cast_rays(t_frame *frame, int x);
void			draw_frame(t_frame *frame);
void			parse_map(t_frame *frame, char *file);
int				on_expose(t_frame *frame);
int				on_loop(t_frame *frame);
int				on_exit(t_frame *frame);
int				on_keypress(int code, t_frame *frame);
int				on_keyrelease(int code, t_frame *frame);
void			on_loop_move(t_frame *frame);
#endif
