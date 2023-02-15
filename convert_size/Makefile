NAME = convert_size
CC = clang
SRC = ./convert_size.c
LIBFT_PATH = ../libft
LIBFT_NAME = libft.a
GNL_SRC = ../get_next_line/get_next_line.c \
			../get_next_line/get_next_line_utils.c

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	$(CC) $(SRC) $(GNL_SRC) $(LIBFT_PATH)/$(LIBFT_NAME) -o $@.out -g
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make re -C $(LIBFT_PATH)
	rm $(NAME).out

re: fclean all

run: all
	./$(NAME)