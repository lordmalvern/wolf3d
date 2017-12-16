# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpuschel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 01:15:13 by bpuschel          #+#    #+#              #
#    Updated: 2017/12/13 22:19:38 by bpuschel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDE = includes/
SRC = srcs/
FILES = update.c draw.c fractol.c init.c hooks.c mouse.c
OBJ = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE) -g -o
LDFLAGS = -Llibft/ -Llibvect/ -Lmlx/
LDLIBS = -lftprintf -lvect -lmlx -framework OpenGL -framework AppKit
.PHONY: all clean fclean re

all: libftprintf-all libvect-all libmlx-all $(NAME)

clean: libftprintf-clean libvect-clean libmlx-clean
	rm -rf $(OBJ)

fclean: libftprintf-fclean libvect-fclean libmlx-clean clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(addprefix $(SRC), $(FILES))
	$(CC) $(CFLAGS) $@ $(LDFLAGS) $(LDLIBS) $^

libftprintf-all:
	cd libft && $(MAKE)

libftprintf-clean:
	cd libft && $(MAKE) clean

libftprintf-fclean:
	cd libft && $(MAKE) fclean

libvect-all:
	cd libvect && $(MAKE)

libvect-clean:
	cd libvect && $(MAKE) clean

libvect-fclean:
	cd libvect && $(MAKE) fclean

libmlx-all:
	cd mlx && $(MAKE)

libmlx-clean:
	cd mlx && $(MAKE) clean

