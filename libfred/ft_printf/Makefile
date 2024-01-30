# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 17:14:40 by fde-carv          #+#    #+#              #
#    Updated: 2023/05/02 12:55:58 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

CC = cc
FLAGS = -Wall -Wextra -Werror
DEPS = ../includes
RM = rm -f
AR = ar -rc

# =============================================================================
#	MANDATORY PART
# =============================================================================

#SRCS_MAND = ${wildcard f*.c}

TARGET = 	ft_printf.o \
				ft_putbase_hex.o \
				ft_putchar.o \
				ft_putnbr.o \
				ft_putpointer.o \
				ft_putstr.o \
				ft_putunbr.o

NAME = libftprintf.a

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@ -I $(DEPS)

all: $(NAME)

$(NAME): $(TARGET)
	cp ../libft/libft.a $(NAME)
	$(AR) $(NAME) $(TARGET)

clean:
	$(RM) $(TARGET) $(BONUS_TARGET)

fclean: clean
	$(RM) $(NAME) $(BONUS_TARGET)

bonus: all

re: fclean all

.SILENT: