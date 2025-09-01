# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 15:42:57 by vhacman           #+#    #+#              #
#    Updated: 2025/09/01 18:30:00 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

CXX			= c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRC_DIR		= src/
OBJ_DIR		= obj/

SRC			= $(wildcard $(SRC_DIR)*.cpp)
OBJS		= $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))
DEPS		= $(OBJS:.o=.d)

ART_DIR		= ART/
ART1		= $(ART_DIR)art1
ART2		= $(ART_DIR)art2
ART3		= $(ART_DIR)art3

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@[ -f "$(ART1)" ] && cat "$(ART1)" || true
	@echo ""

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS) $(DEPS)
	@[ -f "$(ART3)" ] && cat "$(ART3)" || true
	@echo ""

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@[ -f "$(ART2)" ] && cat "$(ART2)" || true
	@echo ""

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
