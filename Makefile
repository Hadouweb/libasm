CC = nasm
FLAG = -Wall -Werror -Wextra

SRC_PATH = ./srcs
INC_PATH = ./includes

HEADER = -I$(INC_PATH)

NAME = libfts.a

SRC = 	$(SRC_PATH)/ft_bzero.s\
		$(SRC_PATH)/ft_strcat.s\
		$(SRC_PATH)/ft_isalpha.s\
		$(SRC_PATH)/ft_isdigit.s\
		$(SRC_PATH)/ft_isalnum.s\
		$(SRC_PATH)/ft_isascii.s\
		$(SRC_PATH)/ft_isprint.s\
		$(SRC_PATH)/ft_toupper.s\
		$(SRC_PATH)/ft_tolower.s\
		$(SRC_PATH)/ft_puts.s\
		$(SRC_PATH)/ft_strlen.s\
		$(SRC_PATH)/ft_memset.s\
		$(SRC_PATH)/ft_memcpy.s\
		$(SRC_PATH)/ft_strdup.s\
		$(SRC_PATH)/ft_cat.s\
		$(SRC_PATH)/ft_list_push_back.s\
		$(SRC_PATH)/ft_list_push_front.s\
		$(SRC_PATH)/ft_list_push_after_node.s\
		$(SRC_PATH)/ft_list_push_before_node.s\
		$(SRC_PATH)/ft_memcmp.s\
		$(SRC_PATH)/ft_memchr.s\

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
