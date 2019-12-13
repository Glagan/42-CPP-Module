# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 18:47:47 by ncolomer          #+#    #+#              #
#    Updated: 2019/12/13 18:51:19 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= megaphone.c
OBJS			= $(SRCS:.c=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= megaphone

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) ${CFLAGS} -o ${NAME} ${OBJS}

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
