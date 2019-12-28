# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 19:21:17 by ncolomer          #+#    #+#              #
#    Updated: 2019/12/28 16:03:03 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Fixed.cpp Expression.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= eval_expr

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)
				./$(NAME) "(18.18 + 3.03) * 2"
				./$(NAME) "2 + 2"
				./$(NAME) "18.18 + 3.03"
				./$(NAME) "-2.42"
				./$(NAME) "-2.42 - -2.42"
				./$(NAME) "-2.42 - 2.42"
				./$(NAME) "--2.42"
				./$(NAME) "-2.42"
				./$(NAME) "-2.42 / 2"
				./$(NAME) "(-2.42 / 2) * 2"
				./$(NAME) "(4.1 * 2.822) * (45 + (78.4 / 4)) * (78.4 + 12.7)"
				./$(NAME) "(4.1 * 2.822) * (45 + (78.4 / 4)) * (78.4 + 12.7 + 0.12 - 0.13 + 7.89)"

.PHONY:			all clean fclean re test
