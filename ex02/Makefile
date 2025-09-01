# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 15:42:57 by vhacman           #+#    #+#              #
#    Updated: 2025/09/01 17:24:59 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= GlobalBanksters
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= 
OBJ_DIR		= obj/
OBJS		= $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

ART_DIR		= ART/
ART1		= $(ART_DIR)art1
ART2		= $(ART_DIR)art2
ART3		= $(ART_DIR)art3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@cat $(ART1)
	@echo ""

$(OBJ_DIR)%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@cat $(ART3)
	@echo ""

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@cat $(ART2)
	@echo ""

re: fclean all

.PHONY: all clean fclean re
