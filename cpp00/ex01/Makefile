# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 16:01:48 by brmaria-          #+#    #+#              #
#    Updated: 2026/05/09 19:09:25 by brmaria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = phonebook
SRC =	srcs/main.cpp \
		srcs/Contact.cpp \
		srcs/PhoneBook.cpp

# compiling flags:
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# files and objects:
OBJ = $(SRC:.cpp=.o)

# rm files and objects
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32mDone ✓\033[m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;32mClean ✓\033[m"

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;32mFClean ✓\033[m"

re: fclean all

.PHONY: all clean fclean re