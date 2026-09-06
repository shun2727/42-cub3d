CFLAGS = #-Wall -Werror -Wextra
CC = gcc 
INC = -I ./includes -I ./Libft
LIBFT = Libft/libft.a

$(LIBFT):
	@$(MAKE) -C Libft

#all the files to include here 
SRC = main.c

#Take whatever is inside SRC, and change .c to .o.
OBJ = $(SRC:.c=.o)

NAME = cub3D

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

clean: 
	@rm -f $(OBJ)
	@$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY : all clean fclean re
