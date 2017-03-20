CC = gcc
FLAG = -Werror -Wextra -Wall -g

SRCS_PATH = ./srcs
INC_PATH = ./includes

HEADER = -I $(INC_PATH)

SRC = $(SRCS_PATH)/main.c\

OBJ = $(SRC:.c=.o)

NAME = libfts.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $^
	@echo "\n\033[39mCompilation done.\033[0m"

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $< $(HEADER)
	@echo "\033[34m█\033[0m\c"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re