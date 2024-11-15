NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar crs
RM = rm -f
SOURCES = \
	ft_printf.c \
	ft_list_manager.c \
	ft_hexadecimal.c \
	ft_printf_func.c \
	ft_strlen.c \
	ft_calloc.c \
	ft_strncmp.c \
	ft_uitoa.c \
	ft_itoa.c \
	ft_bzero.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
