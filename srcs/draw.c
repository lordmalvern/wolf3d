/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:43:44 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/18 15:16:07 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_vect2d	*init_delta(t_frame *f)
{
	double x_2;
	double y_2;

	x_2 = f->r_dir->x * f->r_dir->x;
	y_2 = f->r_dir->y * f->r_dir->y;
	return (init_2d(sqrt(1 + y_2 / x_2), sqrt(1 + x_2 / y_2)));
}

static void		draw_line(t_frame *f, int x, double w, int c)
{
	int			lh;
	int			y;
	int			le;
	double		wx;
	t_vect2d	t;

	lh = HEIGHT / w;
	y = -lh / 2 + HEIGHT / 2;
	y = (y < 0) ? -1 : y - 1;
	le = lh / 2 + HEIGHT / 2;
	le = (le >= HEIGHT) ? HEIGHT - 1 : le;
	wx = (!f->side) ? f->pos->y + w * f->r_dir->y : f->pos->x + w * f->r_dir->x;
	wx -= floor(wx);
	t.x = wx * TEX;
	t.x = (!f->side && f->r_dir->x > 0) ? TEX - t.x - 1 : t.x;
	t.x = (f->side && f->r_dir->y < 0) ? TEX - t.x - 1 : t.x;
	while (++y < le)
	{
		t.y = ((((y << 8) - (HEIGHT << 7) + (lh << 7)) * TEX) / lh) / 256;
		if (f->side == 1)
			draw_to_img(f, x, y,
					(f->tex[c][(int)t.y][(int)t.x] >> 1) & 8355711);
		else
			draw_to_img(f, x, y, f->tex[c][(int)t.y][(int)t.x]);
	}
}

static void		dda(t_frame *f, int x, t_vect2d *delta, t_vect2d *s)
{
	t_vect2d	*map;
	double		wall_dist;

	f->is_wall = 0;
	map = init_2d((int)f->pos->x, (int)f->pos->y);
	while (!f->is_wall)
	{
		f->side = (f->dist->x < f->dist->y) ? 0 : 1;
		if (f->dist->x < f->dist->y)
		{
			f->dist->x += delta->x;
			map->x += s->x;
		}
		else
		{
			f->dist->y += delta->y;
			map->y += s->y;
		}
		f->is_wall = (f->map[(int)map->x][(int)map->y] > 0) ? 1 : 0;
	}
	wall_dist = (!f->side) ?
		((int)map->x - f->pos->x + (1 - s->x) / 2) / f->r_dir->x :
		((int)map->y - f->pos->y + (1 - s->y) / 2) / f->r_dir->y;
	draw_line(f, x, wall_dist, f->map[(int)map->x][(int)map->y] - 1);
	free(map);
}

void			cast_rays(t_frame *f, int x)
{
	double		camera;
	t_vect2d	*delta;
	t_vect2d	*step;

	camera = 2 * x / (double)WIDTH - 1;
	f->r_dir->x = f->dir->x + f->plane->x * camera;
	f->r_dir->y = f->dir->y + f->plane->y * camera;
	step = init_2d((f->r_dir->x < 0) ? -1 : 1, (f->r_dir->y < 0) ? -1 : 1);
	delta = init_delta(f);
	if (f->r_dir->x < 0)
		f->dist->x = (f->pos->x - (int)f->pos->x) * delta->x;
	else
		f->dist->x = ((int)f->pos->x + 1.0 - f->pos->x) * delta->x;
	if (f->r_dir->y < 0)
		f->dist->y = (f->pos->y - (int)f->pos->y) * delta->y;
	else
		f->dist->y = ((int)f->pos->y + 1.0 - f->pos->y) * delta->y;
	dda(f, x, delta, step);
	free(step);
	free(delta);
}

void			draw_frame(t_frame *frame)
{
	int x;

	x = -1;
	while (++x < WIDTH)
		cast_rays(frame, x);
}
