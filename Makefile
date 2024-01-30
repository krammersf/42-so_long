# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 22:02:52 by luide-so          #+#    #+#              #
#    Updated: 2023/08/26 18:27:41 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colours
RESET				=	\033[0m
BLACK 				=	\033[1;30m
RED 				=	\033[1;31m
GREEN 				=	\033[1;32m
YELLOW 				=	\033[1;33m
BLUE				=	\033[1;34m
PURPLE 				=	\033[1;35m
CYAN 				=	\033[1;36m
WHITE 				=	\033[1;37m


NAME 				= 	so_long
NAME_BONUS 			=	so_long_bonus

# Mandatory files
SRC_FILES 			= 	main.c \
						check_map.c \
						exit.c \
						init_game.c \
						key_press.c \
						render_move.c
SRC_DIR 			= 	src
SRC 				= 	${addprefix ${SRC_DIR}/, ${SRC_FILES}}

# Bonus files
SRC_BONUS_FILES 	= 	main_bonus.c \
						check_map_bonus.c \
						exit_bonus.c \
						init_enemy_bonus.c \
						init_enemy_utils_bonus.c \
						init_game_bonus.c \
						key_press_bonus.c \
						render_move_bonus.c \
						game_loop_utils_bonus.c \
						game_loop_bonus.c
SRC_BONUS_DIR 		= 	src_bonus
SRC_BONUS 			=	${addprefix ${SRC_BONUS_DIR}/, ${SRC_BONUS_FILES}}

# Object files
OBJS 				= 	${addprefix obj/, ${SRC_FILES:.c=.o}}
OBJS_BONUS 			= 	${addprefix obj_bonus/, ${SRC_BONUS_FILES:.c=.o}}

# Header files same folder
HEADER_FILES 		= 	so_long.h
HEADER_BONUS_FILES 	= 	so_long_bonus.h
HEADER_DIR 			= 	include
HEADER 				= 	${addprefix ${HEADER_DIR}/, ${HEADER_FILES}}
HEADER_BONUS 		= 	${addprefix ${HEADER_DIR}/, ${HEADER_BONUS_FILES}}

#
INCLUDE 			= 	-I .
LIBFRED 			= 	libfred
LIBFT 				= 	$(LIBFRED)/libft
GET_NEXT_LINE 		= 	$(LIBFRED)/get_next_line
FT_PRINTF 			= 	$(LIBFRED)/ft_printf
MINILIBX 			= 	-L minilibx-linux -lmlx -lXext -lX11
CC 					= 	cc
LIBFT_FLAGS 		= 	-L$(LIBFT) -lft
GET_NEXT_LINE_FLAGS = 	-L$(GET_NEXT_LINE) -lgnl
FT_PRINTF_FLAGS 	= 	-L$(FT_PRINTF) -lftprintf
RM 					= 	rm -f
CFLAGS 				= 	-Wall -Wextra -Werror -g #-03 -fsanitize=address

# Rules
all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	@make bonus -s -C $(LIBFT)
	@make -s -C $(GET_NEXT_LINE)
	@make -s -C $(FT_PRINTF)
	@echo "[${CYAN}Object libfred files ${WHITE}] ${GREEN}--> created${WHITE}"
	@make -s -C minilibx-linux > /dev/null 2>&1
	@echo "[${BLUE}Minilibix files${WHITE}] ${GREEN}--> created${WHITE}\n"
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${OBJS} ${LIBFT_FLAGS} ${GET_NEXT_LINE_FLAGS} ${FT_PRINTF_FLAGS} ${MINILIBX}
	@echo "[${YELLOW}SO_LONG${WHITE}] ${GREEN}--> created${WHITE}\n"

obj/%.o: ${SRC_DIR}/%.c ${HEADER}
	@mkdir -p obj
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${HEADER_BONUS}
	@make -s -C $(LIBFT)
	@make -s -C $(GET_NEXT_LINE)
	@make -s -C $(FT_PRINTF)
	@echo "[${CYAN}Object libfred files ${WHITE}] ${GREEN}--> created${WHITE}"
	@make -s -C minilibx-linux > /dev/null 2>&1
	@echo "[${BLUE}Minilibix files${WHITE}] ${GREEN}--> created${WHITE}\n"	
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT_FLAGS} ${GET_NEXT_LINE_FLAGS} ${FT_PRINTF_FLAGS} ${MINILIBX}
	@echo "[${YELLOW}SO_LONG_BONUS${WHITE}] ${GREEN}--> created${WHITE}\n"

obj_bonus/%.o: ${SRC_BONUS_DIR}/%.c
	@mkdir -p obj_bonus
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"
	
clean:
	@make clean -s -C $(LIBFT)
	@make clean -s -C $(GET_NEXT_LINE)
	@make clean -s -C $(FT_PRINTF)
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r obj obj_bonus
	@echo "\n[${CYAN}Object files${WHITE}] ${RED}--> removed${WHITE}\n"
	@make clean -s -C minilibx-linux > /dev/null 2>&1
	@echo "[${BLUE}Minilibix files${WHITE}] ${RED}--> removed${WHITE}\n"

fclean: clean
	@make fclean -s -C $(LIBFT)
	@make fclean -s -C $(GET_NEXT_LINE)
	@make fclean -s -C $(FT_PRINTF)
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "[${YELLOW}SO_LONG / SO_LONG_BONUS${WHITE}] ${RED}--> removed${WHITE}\n"

fclean2:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r obj obj_bonus
	@echo "\n[${CYAN}Object files ${YELLOW}SO_LONG / SO_LONG_BONUS${WHITE}] ${RED}--> removed${WHITE}\n"
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "[${YELLOW}SO_LONG / SO_LONG_BONUS${WHITE}] ${RED}--> removed${WHITE}\n"

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz

re: fclean all

rebonus: fclean bonus

norm:
	@norminette -R CheckForbiddenSourceHeader > /dev/null 2>&1
	@norminette -R CheckDefine includes > /dev/null 2>&1
	@norminette -R . > /dev/null 2>&1
	@echo "$(GREEN)\n*** >>>  NORMINETTE is OK  <<< ***\n"

norm2:
	@norminette -R CheckForbiddenSourceHeader
	@norminette -R CheckDefine
	@norminette -R .
	@echo "$(GREEN)\n*** >>>  NORMINETTE is OK  <<< ***\n"	

.PHONY: all clean fclean fclean2 re bonus norm norm2 download

#.SILENT: