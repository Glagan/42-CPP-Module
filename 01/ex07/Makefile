# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/15 17:06:28 by ncolomer          #+#    #+#              #
#    Updated: 2019/12/19 18:34:39 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Sed.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= replace

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) *.replace */*.replace

re:				fclean $(NAME)

test:			$(NAME)
				./replace Makefile " " "."
				./replace tests/1 "e" "E"
				./replace tests/2 "cheval" "poney"

.PHONY:			all clean fclean re
