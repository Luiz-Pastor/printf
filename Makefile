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
TEST_EX=test
TEST_SRC=main.c
TEST_OBJ=$(TEST_SRC:%.c=%.o)

t: $(TEST_EX) 
$(TEST_EX): $(NAME) $(TEST_OBJ)
	cc $(TEST_OBJ) -o $(TEST_EX) -L. -lftprintf

main.o: main.c
	cc -c main.c
tclean:
	@rm -rf $(TEST_OBJ) $(TEST_EX)

##########################################

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

##########################################
