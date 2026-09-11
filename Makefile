CFLAGS = -g #-Wall -Werror -Wextra
CC = gcc
LIB = -lXext -lX11 -lm -lbsd

INC = -I ./includes -I ./Libft -I ./minilibx-linux -I ./Libft/ft_printf
LIBFT = Libft/libft.a
MINILIBX = minilibx-linux/libmlx.a

SRC = source/main.c \
	source/mlx_handlers.c \
	source/helper_functions/chr_count.c \
	source/helper_functions/ft_rstrstr.c \
	source/helper_functions/ft_strdup_nl.c \
	source/parsing/read_file.c \
	source/parsing/parse_texture.c

OBJ_DIR = build
OBJ = $(patsubst source/%.c,$(OBJ_DIR)/%.o,$(SRC))

NAME = cub3D

all : $(NAME)

$(LIBFT):
	@$(MAKE) -C Libft

$(MINILIBX):
	@$(MAKE) -C minilibx-linux

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@

$(OBJ_DIR)/%.o : source/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C Libft clean
	@$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY : all clean fclean re
