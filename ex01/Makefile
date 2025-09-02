# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 15:42:57 by vhacman           #+#    #+#              #
#    Updated: 2025/09/02 14:55:27 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = phonebook

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRC_DIR     = src
OBJ_DIR     = obj

SRC = \
  $(SRC_DIR)/Contact/contact.cpp \
  $(SRC_DIR)/Contact/contact_display.cpp \
  $(SRC_DIR)/Core/main.cpp \
  $(SRC_DIR)/Phonebook/phonebook_contacts.cpp \
  $(SRC_DIR)/Phonebook/phonebook_core.cpp \
  $(SRC_DIR)/Phonebook/phonebook_display.cc \
  $(SRC_DIR)/Phonebook/phonebook_input.cpp

# Converte i path src/... in obj/... e le estensioni in .o
OBJS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC))
OBJS := $(OBJS:.cpp=.o)
OBJS := $(OBJS:.cc=.o)

# File di dipendenze generati da -MMD -MP
DEPS = $(OBJS:.o=.d)

ART_DIR     = ART
ART1        = $(ART_DIR)/art1
ART2        = $(ART_DIR)/art2
ART3        = $(ART_DIR)/art3

RM          = rm -f

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@[ -f "$(ART1)" ] && cat "$(ART1)" || true
	@echo ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS) $(DEPS)
	@[ -f "$(ART3)" ] && cat "$(ART3)" || true
	@echo ""

fclean: clean
	@$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)
	@[ -f "$(ART2)" ] && cat "$(ART2)" || true
	@echo ""

re: fclean all

.PHONY: all clean fclean re
