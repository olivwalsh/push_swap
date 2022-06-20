RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -MMD -MP

#MEM = -fsanitize=address

SRC =	src/moves.c \
		src/main.c \
		src/parse_args.c \
		src/init.c \
		src/push_swap.c \
		src/tools.c \
		src/presort.c \
		src/display.c \
		src/move_cost.c \
		src/sort.c

OBJDIR = objs

INCDIR = include

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

DEPS = ${OBJS:.o=.d}

INC = -I./${INCDIR}

LIBFT = ${INCDIR}/libft/libft.a

all: $(NAME)

${LIBFT}: libft

$(NAME): $(OBJ) ${LIBFT}
	@echo -n "Compiling push_swap"
	@$(CC) $(CFLAGS) $(MEM) $(INC) $(OBJ) -o $@ $(LIBFT)
	@echo ${GREEN}"\t\tOK"${RESET}

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(MEM) $(INC) -c $< -o $@

libft:
	@make -s -C${INCDIR}/libft

clean :
	rm -rf $(OBJDIR)
	@make clean -s -C${INCDIR}/libft

fclean: clean
	rm -f $(NAME)
	@make fclean -s -C${INCDIR}/libft

re: fclean all

.PHONY: all clean fclean re bonus libft

-include ${DEPS}