CC = nasm
FLAG = -Wall -Werror -Wextra

SRC_PATH = ./srcs
INC_PATH = ./includes

HEADER = -I$(INC_PATH)

NAME = libfts.a

SRC = $(SRC_PATH)/ft_bzero.s\

OBJ = $(SRC:.s=.o)

all: $(NAME) test

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.s
	@$(CC) $(FLAG) -f macho64 $^ -o $@ $(HEADER)
	@echo "\033[32m█\033[0m\c"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -f test

re: fclean all

test:
	@gcc $(FLAG) main_test.c $(HEADER) -lfts -L. -o test

.PHONY: all clean fclean re
