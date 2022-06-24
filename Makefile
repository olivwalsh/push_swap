RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = push_swap

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

OBJDIR = objs

INCDIR = include

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

INC = -I./${INCDIR}

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "Compiling push_swap"
	@$(CC) $(CFLAGS) $(MEM) $(INC) $(OBJ) -o $@
	@echo ${GREEN}"\t\tOK"${RESET}

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(MEM) $(INC) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus