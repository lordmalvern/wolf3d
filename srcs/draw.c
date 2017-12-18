/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:43:44 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 18:53:15 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"


void			draw_pixel(t_frame *frame, double x, double y, unsigned int c)
{

}

static void		dda(t_frame *f, t_vect2d *dist, t_vect2d *delta, t_vect2d *s)
{
	t_vect2d	*map;
	double		wall_dist;
	int			is_wall;
	int			side;

	is_wall = 0;
	map = init_2d(f->pos->x, f->pos->y);
	while (!is_wall)
	{
		if (dist->x < dist->y)
		{
			dist->x += delta->x;
			map->x += s->x;
			side = 0;
		}
		else
		{
			dist->y += delta->y;
			map->y += s->y;
			side = 1;
		}
		is_wall = (f->map[map->y][map->x] > 0) ? 1 : 0;
	}
}

void			cast_rays(t_frame *frame, int x)
{
	double		camera;
	t_vect2d	*r_dir;
	t_vect2d	*dist;
	t_vect2d	*delta;
	t_vect2d	*step;

	camera = 2 * x / WIDTH - 1;
	r_dir = init_2d(frame->dir->x + frame->plane->x * camera,
			frame->dir->y + frame->plane->y * camera);
	step = init_2d((r_dir->x < 0) ? -1 : 1, (r_dir->y < 0) ? -1 : 1);
	delta = init_2d(sqrt(1 + (r_dir->y * r_dir->y) / (r_dir->x * r_dir->x)),
			sqrt(1 + (r_dir->x * r_dir->x) / (r_dir->y * r_dir->y)));
	dist = init_2d(0, 0);
	if (r_dir->x < 0)
		dist->x = (frame->pos->x - (int)frame->pos->x) * delta->x;
	else
		dist->x = ((int)frame->pos->x + 1.0 - frame->pos->x) * delta->x;
	if (r_dir->y < 0)
		dist->y = (frame->pos->y - (int)frame->pos->y) * delta->y;
	else
		dist->y = ((int)frame->pos->y + 1.0 - frame->pos->y) * delta->y;
	dda(frame, dist, delta, step);
}

void			draw_frame(t_frame *frame)
{
	int x;

	x = -1;
	while (++x < WIDTH)
		cast_rays(frame, x);
}
