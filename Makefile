NAME = so_long
CC = clang
SRC = ./main.c
MAP_SRC = ./map/check_map.c \
			./map/generate_map.c
WIN_SRC = ./window/window.c
PLAYER_SRC = ./player/player.c
KEYBOARD_SRC = ./keyboard/keyboard.c
ENGINE_SRC = ./engine/time.c
GOST_SRC = ./gosts/gost.c
LIBFT_PATH = libft
LIBFT_NAME = libft.a
GNL_SRC = get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	$(CC) -Iminilibx-linux/ $(SRC) $(GOST_SRC) $(MAP_SRC) $(WIN_SRC) $(PLAYER_SRC) $(GNL_SRC) $(KEYBOARD_SRC) $(ENGINE_SRC) -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) -g
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm $(NAME)

re: fclean all

run: all
	./$(NAME)

convert: $(LIBFT_NAME)
	$(CC) convert_size/convert_size.c $(GNL_SRC) $(LIBFT_PATH)/$(LIBFT_NAME) -o convert_size.out -g

clean_convert:
	rm $(NAME) convert_size.out
