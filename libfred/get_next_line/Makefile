# --------- COLOURS ----------------------------------------------- #

RESET = \033[0m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

# --------- COMMANDS ---------------------------------------------- #

CC = cc
AR = ar rcs
RM = rm -rf

# --------- FLAGS ------------------------------------------------- #

CFLAGS = -Wall -Werror -Wextra
MKFLAGS = --no-print-directory

# --------- FOLDERS ----------------------------------------------- #

DEPS = ../includes

# --------- FILES ------------------------------------------------- #

TARGET 			=	get_next_line.o \
					get_next_line_utils.o
BONUS_TARGET 	= 	get_next_line_bonus.o \
					get_next_line_utils_bonus.o
NAME	 		= 	libgnl.a

# --------- RULES ------------------------------------------------- #

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

all: 	$(NAME)

bonus: $(TARGET) $(BONUS_TARGET)
	@$(AR) $(NAME) $^

$(NAME): $(TARGET)
	@$(AR) $(NAME) $^

clean:
	@$(RM) $(TARGET) $(BONUS_TARGET)

fclean: clean
	@$(RM) $(NAME) $(BONUS_TARGET)

re: fclean all