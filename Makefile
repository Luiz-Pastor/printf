##########################################
NAME=libftprintf.a
CC=cc
FLAGS=-Wall -Werror -Wextra
##########################################

SRC_FOLDER=src
SRC=		ft_placeholder_utilities.c	\
			ft_placeholder_string.c		\
			ft_placeholder_number.c		\
			ft_placeholder_pointer.c	\
			ft_placeholder_hexanumber.c	\
			ft_printf.c
OBJ=$(SRC:%.c=%.o)

##########################################

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $^

%.o: $(SRC_FOLDER)/%.c
	$(CC) -c $(FLAGS) $<

##########################################

clear:
	@rm -rf $(OBJ)

fclear: clear
	@rm -rf $(NAME)

re: fclear $(NAME)

.PHONY: all clear fclear re

##########################################
