# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpuschel <bpuschel@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 11:02:38 by bpuschel          #+#    #+#              #
#    Updated: 2017/12/08 01:28:38 by bpuschel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvect.a
INCLUDE = .
FILES = basic_ops_2d.c basic_ops_3d.c transform.c init.c mat_ops.c
OBJ = $(FILES:.c=.o)
.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I $(INCLUDE) -c $(FILES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
