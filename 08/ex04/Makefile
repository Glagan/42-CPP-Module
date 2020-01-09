# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 19:36:38 by ncolomer          #+#    #+#              #
#    Updated: 2020/01/09 15:50:47 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Postfix.cpp Token.cpp \
					Tokens/Num.cpp Tokens/Op.cpp Tokens/ParOpen.cpp Tokens/ParClose.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= postfix

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)
				./postfix "3 + ((1 + 4) * 2) - 1"
				@echo ""
				./postfix ""
				@echo ""
				./postfix "1"
				@echo ""
				./postfix "1 + 1"
				@echo ""
				./postfix "(2 * ((3 / 1) + ((3 * 3) * 5)) - 6) / 2"
				@echo ""
				./postfix "+"
				@echo ""
				./postfix "-"
				@echo ""
				./postfix "*"
				@echo ""
				./postfix "/"
				@echo ""
				./postfix " "
				@echo ""
				./postfix "1 / 0"
				@echo ""
				./postfix "++1"
				@echo ""
				./postfix "--1"
				@echo ""
				./postfix "+1"
				@echo ""
				./postfix "-1"
				@echo ""
				./postfix "-1 - -1"
				@echo ""
				./postfix "-1 - -1 + (-1)"
				@echo ""
				./postfix "424242424242"
				@echo ""
				./postfix "expression"

.PHONY:			all clean fclean re test
