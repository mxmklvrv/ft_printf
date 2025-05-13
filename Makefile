# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 14:45:30 by mklevero          #+#    #+#              #
#    Updated: 2025/05/13 16:58:25 by mklevero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	%(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 