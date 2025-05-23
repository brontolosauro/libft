NAME = libft.a

SRC =	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c \
		ft_isascii.c ft_tolower.c ft_toupper.c ft_strlcpy.c ft_strlcat.c \
		ft_atoi.c ft_strchr.c  ft_strrchr.c ft_strncmp.c ft_strnstr.c \
		ft_strdup.c ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memset.c \
		ft_memcpy.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_memmove.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_printf.c ft_vprintf.c ft_parse_convspec.c ft_print_arg.c \
		ft_conv_char.c ft_conv_str.c ft_conv_ptr.c ft_conv_int.c \
		ft_conv_uint.c ft_conv_hex.c ft_conv_chex.c ft_conv_percent.c \
		ft_uitoa.c ft_xitoa.c ft_lxitoa.c
		
OBJ = $(SRC:%.c=%.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : libft.h $(OBJ)
	ar rcs $(NAME) $(OBJ)


clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean all
