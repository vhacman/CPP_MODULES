# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 12:39:56 by vhacman           #+#    #+#              #
#    Updated: 2025/09/03 12:39:58 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 GlobalBanksters                              #
# **************************************************************************** #

NAME       := GlobalBanksters
CXX        := c++
CXXFLAGS   := -Wall -Wextra -Werror -std=c++98
CPPFLAGS   := -Iincludes
DEPFLAGS   := -MMD -MP

SRC        := src/Account.cpp \
              src/tests.cpp

HDRS       := includes/Account.hpp

OBJ_DIR    := obj
OBJS       := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPS       := $(OBJS:.o=.d)

ART_DIR    := ART
ART1       := $(ART_DIR)/art1
ART2       := $(ART_DIR)/art2
ART3       := $(ART_DIR)/art3

# -------------------------------- Targets ---------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@[ -f "$(ART1)" ] && cat "$(ART1)" || true
	@echo

# Compila in obj/ mantenendo l'albero delle cartelle e generando i .d
$(OBJ_DIR)/%.o: %.cpp $(HDRS) | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS) $(DEPS)
	@[ -f "$(ART3)" ] && cat "$(ART3)" || true
	@echo

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@[ -f "$(ART2)" ] && cat "$(ART2)" || true
	@echo

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
