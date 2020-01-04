# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 19:21:17 by ncolomer          #+#    #+#              #
#    Updated: 2020/01/04 16:28:45 by ncolomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.cpp Interpreter.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -std=c++98 -Wall -Wextra -Werror -I.

NAME			= convert

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)
				./convert 0
				./convert 42
				./convert 42.
				./convert 42.f
				./convert nan
				./convert nanf
				./convert inf
				./convert inff
				./convert +inf
				./convert +inff
				./convert -inf
				./convert -inff
				./convert 2147483647
				./convert 2147483648
				./convert -2147483648
				./convert -2147483649
				./convert 2147483647.f
				./convert 2147483648.f
				./convert -2147483648.f
				./convert -2147483649.f
				./convert 2147483647.
				./convert 2147483648.
				./convert -2147483648.
				./convert -2147483649.
				./convert a
				./convert B
				./convert "~"
				./convert 126
				./convert test
				./convert 58
				./convert 101
				./convert 457846
				./convert 12544.545f
				./convert 54178652.41784187
				./convert 0e0
				./convert 0e+0
				./convert 0e-0
				./convert 0.5e-0
				./convert 454874.5e-0
				./convert 454874.5e-21
				./convert 454874.5e+21
				./convert 3.40282e+38
				./convert 3.5e+38
				./convert 1.17549e-38
				./convert 1.2e-38
				./convert -1.17549e38
				./convert -1.2e38
				./convert 0e0f
				./convert 0e+0f
				./convert 0e-0f
				./convert 0.5e-0f
				./convert 454874.5e-0f
				./convert 454874.5e-21f
				./convert 454874.5e+21f
				./convert 3.40282e+38f
				./convert 3.5e+38f
				./convert 1.17549e-38f
				./convert 1.2e-38f
				./convert -1.17549e38f
				./convert -1.2e38f

.PHONY:			all clean fclean re test
