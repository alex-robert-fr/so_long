NAME = so_long
CC = clang
SRC = ./main.c
LIBFT_PATH = libft
LIBFT_NAME = libft.a
GNL_SRC = get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	$(CC) -Iminilibx-linux/ $(SRC) -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) -g
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm $(NAME) convert_size.out

re: fclean all

run: all
	./$(NAME)

convert: $(LIBFT_NAME)
	$(CC) convert_size/convert_size.c $(GNL_SRC) $(LIBFT_PATH)/$(LIBFT_NAME) -o convert_size.out -g