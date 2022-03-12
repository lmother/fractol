# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmother <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 15:28:34 by lmother           #+#    #+#              #
#    Updated: 2021/06/06 15:42:00 by lmother          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_LIB		=	./Libft
LIBFT		=	libft.a
INC			=	./includes/fractol.h

NAME		=	fractol

SRCS		=	fractol.c\
				keys.c\
				init.c\
				help.c\
				draw.c\
				zoom.c

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c $(INC)
			$(CC) $(CFLAGS)  -c $< -o $(<:.c=.o)

CC			=	gcc

RM			=	rm -rf

MLX			=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
CFLAGS		=	-Wall -Wextra -Werror -O3 -include $(INC)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(SRC_LIB)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS) $(SRC_LIB)/$(LIBFT)

clean:
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) clean -C $(SRC_LIB)
			$(RM) $(NAME)

re :		fclean all

.PHONY:	all clean fclean re bonus
