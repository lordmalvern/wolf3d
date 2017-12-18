/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:25:50 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/17 21:18:39 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	fill_map(t_frame *frame, int fd)
{
	int y;
	int x;
	char *buff;
	char **row;

	y = 0;
	frame->map = (int **)malloc(frame->height * sizeof(int *));
	while (get_next_line(fd, &buff))
	{
		row = ft_strsplit(buff, ' ');
		frame->map[y] = (int *)malloc(frame->width * sizeof(int));
		x = -1;
		while (++x < frame->width)
		{
			frame[y][x] = ft_atoi(row[x]);
			free(row[x]);
		}
		free(row);
		y++;
	}
	free(buff);
}

static void	get_dims(t_frame *frame, int fd)
{
	char *buff;
	char **row;
	int width;

	frame->height = 0;
	while (get_next_line(fd, &buff))
	{
		row = ft_strsplit(buff, ' ');
		width = -1;
		while (buff[++width])
			if (!ft_isdigit(buff[width]))
			{
				ft_putendl("Error: invalid map");
				exit(1);
			}
		if (frame->width != 0 && frame->width < width)
		{
			ft_putendl("Error: invalid map");
			exit(1);
		}
		frame->width = width;
		frame->height++;
	}
	free(buff);
}

void		parse_map(t_frame *frame, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error: Invalid file path");
		exit(1);
	}
	get_dims(frame, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	fill_map(frame, fd);
	close(fd);
}

static void	wolf3d(t_frame *frame)
{
	set_hooks(frame);
	set_palette(frame);
	refresh(frame);
	mlx_loop(frame->mlx);
}

int			main(int argc, char **argv)
{
	t_frame *frame;

	if (argc == 2)
	{
		frame = init_frame();
		parse_map(frame, argv[1]);
		wolf3d(frame);
	}
	return (0);
}
