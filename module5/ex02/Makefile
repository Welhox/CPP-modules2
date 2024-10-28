# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 10:53:06 by clundber          #+#    #+#              #
#    Updated: 2024/10/28 15:42:57 by clundber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

# ------------ PROJECT -------#
NAME = Bureaucracy

#------------- SOURCE FILES ------#
CFILES = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp

OFILES = $(CFILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#--------- FLAGS ----------#
CC = @c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

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