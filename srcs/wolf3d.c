/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:25:50 by bpuschel          #+#    #+#             */
/*   Updated: 2017/12/18 12:22:19 by bpuschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	print_err(char *err)
{
	ft_putendl(err);
	exit(1);
}

static void	fill_map(t_frame *frame, int fd)
{
	int		y;
	int		x;
	char	*buff;
	char	**row;

	y = 0;
	frame->map = (int **)malloc(frame->height * sizeof(int *));
	while (get_next_line(fd, &buff))
	{
		row = ft_strsplit(buff, ' ');
		frame->map[y] = (int *)malloc(frame->width * sizeof(int));
		x = -1;
		while (++x < frame->width)
		{
			frame->map[y][x] = ft_atoi(row[x]);
			free(row[x]);
		}
		free(row);
		y++;
		free(buff);
	}
}

static void	get_dims(t_frame *frame, int fd)
{
	char	*buff;
	char	**row;
	int		width;

	frame->height = 0;
	while (get_next_line(fd, &buff))
	{
		row = ft_strsplit(buff, ' ');
		width = -1;
		while (row[++width])
		{
			if (!ft_isdigit(row[width][0]))
				print_err("Error: invalid map");
			free(row[width]);
		}
		if (frame->width != 0 && frame->width < width)
			print_err("Error: invalid map");
		frame->width = width;
		frame->height++;
		free(row);
		free(buff);
	}
}

void		parse_map(t_frame *frame, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Error: Invalid file path");
	get_dims(frame, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	fill_map(frame, fd);
	close(fd);
}

int			main(int argc, char **argv)
{
	t_frame *frame;

	if (argc == 1 && argv)
	{
		frame = init_frame();
		parse_map(frame, "map");
		set_hooks(frame);
		set_palette(frame);
		refresh(frame);
		ft_putendl("Controls:\n"
				"W or Up Arrow: Move forward\n"
				"S or Down Arrow: Move backward\n"
				"A or Left Arrow: Turn left\n"
				"D or Right Arrow: Turn right");
		mlx_loop(frame->mlx);
		free(frame);
	}
	else
		print_err("Usage: ./wolf3d");
	return (0);
}
