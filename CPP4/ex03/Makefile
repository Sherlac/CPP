# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/04/11 12:35:25 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= interface


# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= c++

CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g3 -O2

LFLAGS			= -Wall -Wextra -Werror -std=c++98 -g3 -O2


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRCS		= main.cpp \
			  AMateria.cpp \
			  Cure.cpp \
			  Ice.cpp \
			  Character.cpp \
			  MateriaSource.cpp

OBJ			:= $(SRCS:.cpp=.o)


# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #


GREEN		= \033[32;1m
RED			= \033[31;1m
YELLOW		= \033[33;1m
CYAN		= \033[36;1m
RESET		= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

.SILENT : all

all : header $(NAME) footer

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
		$(CC) $(LFLAGS) $(OBJ) -o $(NAME)

leaks :	re
		valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes ./$(NAME)

install: re
		cp $(NAME) ~/bin

clean :
		@-rm -f $(OBJ)
		@printf "$(RED)"
		@printf "Object files removed\n"
		@printf "$(RESET)"

fclean :
		@-rm -f $(NAME)
		@-rm -f $(OBJ)
		@printf "$(RED)"
		@printf "Binary and object files removed\n"
		@printf "$(RESET)"

re :	fclean all

.PHONY : fclean

header:
		@printf "$(CYAN)"
		@printf "CPP module04 ex02 :\n"
		@printf "$(RESET)"

footer: 
		@printf "$(CYAN)"
		@printf "Usage:\n"
		@printf "$(RESET)"
		@printf "./" 
		@printf $(NAME)
		@printf "\n"
