/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:43:44 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 21:47:27 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		draw_line(t_frame *f, int x, double wall_dist, int c)
{
	int			lh;
	int			y;
	int			le;
	double		wall;
	t_vect2d	tex;

	lh = HEIGHT / wall_dist;
	y = -lh / 2 + HEIGHT / 2;
	y = (ls < 0) ? 0 : ls;
	le = lh / 2 + HEIGHT / 2;
	le = (le >= HEIGHT) ? HEIGHT - 1 : le;
	wall = (!side) ? f->pos->y + wall_dist * f->r_dir->y :
		f->pos->x + wall_dist * f->r_dir->x;
	wall -= floor(wall);
	tex.x = wall * TEX;
	tex.x = (!side && f->r_dir->x > 0) ? TEX - tex.x - 1 : tex.x;
	tex.x = (side && f->r_dir->y < 0) ? TEX - tex.x - 1 : tex.x;
	while (y < le)
	{
		tex.y = (((y * 256 - HEIGHT * 128 + lh * 128) * TEX) / lh) / 256;
		if (side == 1)
			mlx_pixel_put(f->mlx, f->win, x, y, f->tex[c][tex.y][tex.x] / 2);
		else
			mlx_pixel_put(f->mlx, f->win, x, y, f->tex[c][tex.y][tex.x]);
	}
}

static void		dda(t_frame *f, int x, t_vect2d *delta, t_vect2d *s)
{
	t_vect2d	*map;
	double		wall_dist;

	f->is_wall = 0;
	map = init_2d(f->pos->x, f->pos->y);
	while (!f->is_wall)
	{
		if (f->dist->x < f->dist->y)
		{
			f->dist->x += delta->x;
			map->x += s->x;
			f->side = 0;
		}
		else
		{
			f->dist->y += delta->y;
			map->y += s->y;
			f->side = 1;
		}
		f->is_wall = (f->map[map->y][map->x] > 0) ? 1 : 0;
	}
	wall_dist = (!f->side) ?
		(map->x - f->pos->x + (1 - s->x) / 2) / f->r_dir->x :
		(map->y - f->pos->y + (1 - s->y) / 2) / f->r_dir->y;
	draw_line(f, x, wall_dist, f->map[map->y][map->x] - 1);
}

void			cast_rays(t_frame *f, int x)
{
	double		camera;
	t_vect2d	*delta;
	t_vect2d	*step;

	camera = 2 * x / WIDTH - 1;
	f->r_dir->x = f->dir->x + f->plane->x * camera;
	f->r_dir->y = f->dir->y + f->plane->y * camera;
	step = init_2d((f->r_dir->x < 0) ? -1 : 1, (f->r_dir->y < 0) ? -1 : 1);
	delta = init_2d(
			sqrt(1 + (f->r_dir->y * f->r_dir->y) / (f->r_dir->x * f->r_dir->x)),
			sqrt(1 + (f->r_dir->x * f->r_dir->x) / (f->r_dir->y * f->r_dir->y))
			);
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
