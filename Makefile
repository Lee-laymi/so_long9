# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ami <ami@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 22:55:16 by skrairab          #+#    #+#              #
#    Updated: 2022/12/18 16:52:51 by ami              ###   ########.fr        #
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
	   rm -rf *.o
	   rm -rf ft_getnextline/*.o
		make -C $(LIBDIR)  clean
		make -C $(LIBPRINTF) clean
		@make clean -C mlx/

fclean: clean
		rm -rf $(NAME)
		make -C $(LIBDIR) fclean
		make -C $(LIBPRINTF) fclean

re: fclean all

.PHONY: all clean fclean re