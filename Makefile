RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC =	src/moves.c \
		src/push_swap.c \
		src/parse_args.c

OBJDIR = objs

INCDIR = include

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

INC = -I./${INCDIR}

LIBFT = -L./${INCDIR}/libft -lft

all: $(NAME) 

$(NAME): $(OBJ) libft 
	$(CC) $(CFLAGS) $(INC) -O3 $(OBJ) -o $@ $(LIBFT)

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

libft:
	@echo -n "Compiling libft"
	@make -s -C${INCDIR}/libft
	@echo ${GREEN}"\t\tOK"${RESET}

clean :
	rm -rf $(OBJDIR)
	@make clean -s -C${INCDIR}/libft

fclean: clean
	rm -f $(NAME)
	@make fclean -s -C${INCDIR}/libft

re: fclean all

.PHONY: all clean fclean re bonus libft