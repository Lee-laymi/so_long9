# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 11:49:40 by skrairab          #+#    #+#              #
#    Updated: 2023/02/22 11:55:55 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c\
		ft_opened.c\
		ft_floodfill.c\
		checker1.c\
		checker2.c\
		create_map.c\
		ft_getnextline/get_next_line_utils.c\
		ft_getnextline/get_next_line.c\
		ft_keyhook.c

NAME = so_long

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBDIR = Libfts

LIBPRINTF = ft_printf

INCLUDE = -L Libfts -lft -L ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C mlx/
	make -C $(LIBDIR)
	make -C $(LIBPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME) $(INCLUDE)


clean:
		rm -rf $(OBJS)
		make -C $(LIBDIR)  clean
		make -C $(LIBPRINTF) clean
		@make clean -C mlx/

fclean: clean
		rm -rf $(NAME)
		make -C $(LIBDIR) fclean
		make -C $(LIBPRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
