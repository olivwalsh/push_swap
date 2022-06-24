RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRC =	src/basic_moves.c \
		src/r_moves.c \
		src/main.c \
		src/parse_args.c \
		src/init.c \
		src/push_swap.c \
		src/tools.c \
		src/presort.c \
		src/display.c \
		src/move_cost.c \
		src/sort.c \
		src/indexes.c \
		src/sort_big.c

BONUS_SRC =	bonus/main.c \
			bonus/bonus_args.c \
			bonus/bonus_init.c \
			bonus/bonus_b_moves.c \
			bonus/bonus_r_moves.c \
			bonus/bonus_utils.c \
			bonus/bonus_utils2.c \
			bonus/bonus_presort.c

OBJDIR = objs

INCDIR = include

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

BONUS_OBJ = $(addprefix ${OBJDIR}/,${BONUS_SRC:.c=.o})

INC = -I./${INCDIR}

all: $(NAME) 

$(NAME): $(OBJ)
	@echo -n "Compiling push_swap"
	@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $@
	@echo ${GREEN}"\t\tOK"${RESET}

$(BONUS): $(BONUS_OBJ)
	@echo -n "Compiling checker"
	@$(CC) $(CFLAGS) $(INC) $(BONUS_OBJ) -o $@
	@echo ${GREEN}"\t\tOK"${RESET}

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus : $(BONUS)

clean :
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus