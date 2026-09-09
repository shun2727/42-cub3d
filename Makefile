CFLAGS = #-Wall -Werror -Wextra
CC = gcc
LIB = -lXext -lX11 -lm -lbsd

INC = -I ./includes -I ./Libft -I ./minilibx-linux -I ./ft_printf_helper
LIBFT = Libft/libft.a
MINILIBX = minilibx-linux/libmlx.a

$(LIBFT):
	@$(MAKE) -C Libft

$(MINILIBX):
	@$(MAKE) -C minilibx-linux

#all the files to include here 
SRC = main.c check_file.c read_file.c mlx_handlers.c

#Take whatever is inside SRC, and change .c to .o.
OBJ = $(SRC:.c=.o)

NAME = cub3D

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

clean: 
	@rm -f $(OBJ)
	@$(MAKE) -C Libft clean
	@$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY : all clean fclean re
