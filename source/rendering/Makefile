
NAME = testing
NAME_FLAGS = -Wall -Wextra -Werror mlx_linux/libmlx_Linux.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o -Ilibft
OBJ_FLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -Includes -Ilibft
CC = cc
RM = rm -f

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

SRC =	test.c \
	init.c \
	put_pixel.c \
	render.c

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(NAME_FLAGS) -o $(NAME)

test: $(LIBFT) main.o
	$(CC) main.o $(LIBFT) $(NAME_FLAGS) -o test

$(LIBFT):
	$(MAKE) -C $(LIB_PATH)

%.o: %.c $(INCS)
	$(CC) $(OBJ_FLAGS) -c $< -o $@

bonus: $(BONUSES:.c=.o)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: re fclean bonus all clean


