# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 11:26:51 by clundber          #+#    #+#              #
#    Updated: 2025/02/10 11:51:50 by clundber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

# ------------ PROJECT -------#
NAME = PmergeMe
#------------- SOURCE FILES ------#
CFILES = main.cpp  PmergeMe.cpp

OFILES = $(CFILES:.cpp=.o)

HEADERS = PmergeMe.hpp

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

#--------- FLAGS ----------#
CC = @c++
CFLAGS = -Wall -Wextra -Werror -std=c++20

#------------------#

all: $(NAME)

$(NAME): $(OFILES)
	@echo "$(COLOUR_BLUE)compiling $(NAME)$(COLOUR_END)"
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME) 
	@echo "$(COLOUR_GREEN)$(NAME) compiled successfully$(COLOUR_END)"

clean:
	@echo "$(COLOUR_GREEN)cleaning $(NAME)$(COLOUR_END)"
	@rm -f $(OFILES) 

fclean: clean
	@rm -f $(NAME) 
	@rm -f $(OFILES)  

re: fclean all 

.PHONY: all clean fclean re