# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#              #
#    Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = iter
SRC =	srcs/main.cpp \

# compiling flags:
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# files and objects:
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

# rm files and objects
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32mDone ✓\033[m"

clean:
	@$(RM) $(OBJ) $(DEP)
	@echo "\033[0;32mClean ✓\033[m"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -MMD -MP -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32mFClean ✓\033[m"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
