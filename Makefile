# Directories #
SRCDIR =
HDRDIR =
OBJDIR =
# Names #
NAME = libft.a
MAIN_NAME = a.out
# Compiler & COptions & CFlags #
CFLAGS = -g -Werror -Wall -Wextra
COPTIONS = -c
CC = cc
# Source Files #
SRC =  	ft_atoi.c		ft_itoa.c		ft_putnbr_fd.c	ft_strlcpy.c	ft_tolower.c	\
		ft_bzero.c		ft_memchr.c		ft_putstr_fd.c  ft_strlen.c		ft_toupper.c	\
		ft_calloc.c		ft_memcmp.c 	ft_split.c		ft_strmapi.c	ft_isalnum.c	\
		ft_memcpy.c		ft_strchr.c		ft_strncmp.c	ft_isalpha.c	ft_memmove.c	\
		ft_strdup.c		ft_strnstr.c	ft_isascii.c	ft_memset.c		ft_striteri.c	\
		ft_strrchr.c	ft_isdigit.c	ft_putchar_fd.c	ft_strjoin.c	ft_strtrim.c	\
		ft_isprint.c	ft_putendl_fd.c	ft_strlcat.c	ft_substr.c
BONUS_SRC =
MAIN_SRC = main.c
TEST_SRC = ft_putstr_non_printable.c
HEADERS = libft.h

# Object Files #
SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# Targets #
all : $(NAME)

$(NAME): $(SRC_OBJ)
	ar rcvs $(NAME) $(SRC_OBJ)

#bonus: $(BONUS_OBJ)
#	ar rcvs $(NAME) $(BONUS_OBJ)

test: $(MAIN_OBJ) $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(SRC_OBJ) $(TEST_OBJ) -o $(MAIN_NAME)

run: fclean test
	./a.out | cat -e
debug: fclean test
	gdb ./a.out

# Compile .c to .o #
%.o: %.c
	$(CC) $(CFLAGS) $(COPTIONS) $^ -o $@

clean:
	rm -f $(SRC_OBJ)
	rm -f $(MAIN_OBJ)
	rm -f $(BONUS_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f $(NAME) $(MAIN_NAME)

re: fclean all

name:
	@echo "$(NAME)"

help:
	@echo "Possible Commands:"
	@echo "all --> Compile whole project"
	@echo "name --> Display project name"
	@echo "bonus --> Compile bonus if available project"
	@echo "test --> Compile main if available"
	@echo "run --> Run main if available"
	@echo "debug --> Run GDB with a.out"
	@echo "clean --> Delete all object files"
	@echo "fclean --> Delete everything besides source files"
	@echo "re --> recompile everything (fclean, all)"

.PHONY: all clean fclean re name help bonus run debug
