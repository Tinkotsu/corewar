LIBFT	=	libft/libft.a

NAME	=	corewar
HEAD	=	corewar.h
HEAD_GAME =	game.h
HEAD_OP	=	op.h

INC_DIR	=	./includes/
LIB_DIR	=	./libft/includes/
SRC_DIR	=	./src/
OBJ_DIR	=	./objs/

SRC		=   carriage.c	\
		    champ_op.c	\
		    corewar_init.c  \
		    display_arena.c \
		    endgame.c	    \
		    error.c	    \
		    game.c	    \
		    game_init.c	    \
		    int_ops.c	    \
		    main.c	    \
		    op.c	    \
		    parse_players.c \
		    players_init.c  \
		    add.c \
		    aff.c \
		    and.c \
		    check_pos.c \
		    fork.c  \
		    get_args.c \
		    ld.c \
		    ldi.c \
		    lfork.c \
		    live.c \
		    lld.c \
		    lldi.c \
		    ops_array.c \
		    or.c \
		    st.c \
		    sti.c \
		    sub.c \
		    xor.c \
		    zjmp.c


HEADER	=	$(addprefix $(INC_DIR), $(HEAD))

OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

COMP_LIB = make -C libft/
CC		= gcc -g
FLAGS	= -Wall -Wextra -Werror
CC_LIB	= -L ./libft -lft

all: lib $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(addprefix -I, $(INC_DIR)) $(OBJ) $(FLAGS) -o $(NAME) $(CC_LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(COMP_LIB)

lib:
	$(COMP_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c  $(HEADER)
	$(CC) -I $(INC_DIR) -I $(LIB_DIR) $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME) $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
