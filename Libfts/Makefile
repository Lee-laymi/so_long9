# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 14:47:33 by skrairab          #+#    #+#              #
#    Updated: 2022/04/07 22:30:24 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c\
       ft_bzero.c\
       ft_calloc.c\
       ft_isalnum.c\
       ft_isalpha.c\
       ft_isascii.c\
       ft_isdigit.c\
       ft_isprint.c\
       ft_itoa.c\
       ft_memchr.c\
       ft_memcmp.c\
       ft_memcpy.c\
       ft_memmove.c\
       ft_memset.c\
       ft_putchar_fd.c\
       ft_putendl_fd.c\
       ft_putnbr_fd.c\
       ft_putstr_fd.c\
       ft_split.c\
       ft_strchr.c\
       ft_strdup.c\
       ft_strjoin.c\
       ft_strlcat.c\
       ft_strlcpy.c\
       ft_strlen.c\
       ft_strncmp.c\
       ft_strnstr.c\
       ft_strrchr.c\
       ft_strtrim.c\
       ft_substr.c\
       ft_tolower.c\
       ft_toupper.c\
       ft_striteri.c\
       ft_strmapi.c
      
BONUSC = ft_lstnew.c\
	 ft_lstadd_front.c\
	 ft_lstsize.c\
	 ft_lstlast.c\
	 ft_lstadd_back.c\
	 ft_lstdelone.c\
	 ft_lstclear.c\
	 ft_lstiter.c\
	 ft_lstmap.c

SRCS_BONUS = $(SRCS)\
	     $(BONUSC)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS = $(SRCS:.c=.o)

NAME = libft.a

CC = gcc

CC_FLAGS = -c -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

clean: 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
