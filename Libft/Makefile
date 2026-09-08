CFLAGS = -Wall -Werror -Wextra
INC = -I. -I./ft_printf_helper
CC = gcc

HEADER = libft.h ft_printf_helper/ft_printf.h get_next_line.h

SRC =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_tolower.c ft_toupper.c ft_strtrim.c ft_split.c \
ft_substr.c ft_strjoin.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c \
ft_printf.c \
ft_printf_helper/ft_putchar_fd.c ft_printf_helper/ft_putnbr_fd.c \
ft_printf_helper/ft_putstr_fd.c ft_printf_helper/ft_putnbr_hex.c \
ft_printf_helper/ft_putptr.c \
get_next_line.c \
get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "Cleaning LIBFT object files.... \n"

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re 

