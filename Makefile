##########################################
NAME=libftprintf.a
FLAGS=-Wall -Werror -Wextra
CC=cc
##########################################
C_FOLDER=src
C_SRC=		ft_placeholder_utilities.c	\
			ft_placeholder_string.c		\
			ft_placeholder_number.c		\
			ft_placeholder_pointer.c	\
			ft_placeholder_hexanumber.c	\
			ft_printf.c
C_OBJECTS=$(C_SRC:%.c=%.o)
##########################################

all: $(NAME)

$(NAME): $(C_OBJECTS)
	ar crs $(NAME) $^

%.o: $(C_FOLDER)/%.c
	$(CC) -c $(FLAGS) $<

##########################################

clear:
	@rm -rf $(C_OBJECTS)

fclear: clear
	@rm -rf $(NAME)

re: fclear $(NAME)

.PHONY: clear fclear re

##########################################
