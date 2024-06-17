NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address -g3
RM = rm -rf

SRC = main.c parser.c utils.c push.c swap.c rotate.c reverse.c
OBJ_DIR = obj
OBJ = $(addprefix ${OBJ_DIR}/, ${SRC:%.c=%.o})

###COLORS###
RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
END_LINE = \033[0m
############

all: $(NAME)

${NAME}: ${OBJ}
	@echo "================================================================"
	@echo "  _____  _    _  _____ _    _    _______          __     _____  "
	@echo " |  __ \| |  | |/ ____| |  | |  / ____\ \        / /\   |  __ \ "
	@echo " | |__) | |  | | (___ | |__| | | (___  \ \  /\  / /  \  | |__) |"
	@echo " |  ___/| |  | |\___ \|  __  |  \___ \  \ \/  \/ / /\ \ |  ___/ "
	@echo " | |    | |__| |____) | |  | |  ____) |  \  /\  / ____ \| |     "
	@echo " |_|     \____/|_____/|_|  |_| |_____/    \/  \/_/    \_\_|     "
	@echo "================================================================"
	@echo
	@echo "$(YELLOW)Compiling Libft...$(END_LINE)"
	@${MAKE} -C ./includes/Libft
	@echo "$(GREEN)Libft successfully compiled.$(END_LINE)"
	@echo "$(YELLOW)Compiling ${NAME}...$(END_LINE)"
	@${CC} ${CFLAGS} ${OBJ} ./includes/Libft/libft.a -o $(NAME)
	@echo "$(GREEN)${NAME} successfully compiled.$(END_LINE)"

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo

clean:
	@echo "================================================================"
	@echo "$(YELLOW)Cleaning Libft...$(END_LINE)"
	@${MAKE} -C ./includes/Libft/ fclean
	@echo "$(GREEN)Libft object files removed.$(END_LINE)"
	@echo "${YELLOW}Cleaning ${NAME}...${END_LINE}"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)${NAME} successfully removed from system.$(END_LINE)"
fclean: clean
	@$(RM) $(NAME)

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

.PHONY: all clean fclean re