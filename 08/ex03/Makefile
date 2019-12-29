# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 18:01:14 by ncolomer          #+#    #+#              #
#    Updated: 2019/12/29 18:49:15 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp MindOpen.cpp Instruction.cpp Program.cpp \
					Instructions/Decr.cpp Instructions/Incr.cpp Instructions/DecrPtr.cpp \
					Instructions/IncrPtr.cpp Instructions/Input.cpp Instructions/Output.cpp \
					Instructions/LoopStart.cpp Instructions/LoopEnd.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= mindopen

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
