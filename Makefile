LIBFT	=	libft/libft.a

NAME	=	corewar
HEAD_CW	=	corewar.h
HEAD_GAME =	game.h
HEAD_OP	=	op.h

INC_DIR	=	./includes/
LIB_DIR	=	./libft/
SRC_DIR	=	./src/
CHAMP_OPS_DIR = ./champ_ops/
OBJ_DIR	=	./objs/

SRC		=   carriage.c				\
		    champ_op.c				\
		    corewar_init.c			\
		    display_arena.c			\
		    endgame.c				\
		    error.c					\
		    game.c					\
		    game_init.c				\
		    int_ops.c				\
		    main.c					\
		    op.c					\
		    parse_players.c			\
		    players_init.c			\
		    check_pos.c				\
		    get_args.c				\
		    champ_ops/fork.c 		\
		    champ_ops/add.c			\
		    champ_ops/aff.c			\
		    champ_ops/and.c			\
		    champ_ops/ld.c			\
		    champ_ops/ldi.c			\
		    champ_ops/lfork.c		\
		    champ_ops/live.c		\
		    champ_ops/lld.c			\
		    champ_ops/lldi.c		\
		    champ_ops/ops_array.c	\
		    champ_ops/or.c			\
		    champ_ops/st.c			\
		    champ_ops/sti.c			\
		    champ_ops/sub.c			\
		    champ_ops/xor.c			\
		    champ_ops/zjmp.c


HEADER_CW	=	$(addprefix $(INC_DIR), $(HEAD_CW))
HEADER_OP	=	$(addprefix $(INC_DIR), $(HEAD_OP))
HEADER_GAME	=	$(addprefix $(INC_DIR), $(HEAD_GAME))

LIB_INC = $(addprefix $(LIB_DIR), $(INC_DIR))

OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

COMP_LIB = make -C $(LIB_DIR)
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
CC_LIB	= -L ./libft -lft

all: lib $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(addprefix -I, $(INC_DIR)) $(OBJ) $(FLAGS) -o $(NAME) $(CC_LIB)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(CHAMP_OPS_DIR)

$(LIBFT):
	$(COMP_LIB)

lib:
	$(COMP_LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_CW) $(HEADER_OP)
	$(CC) -I $(INC_DIR) -I $(LIB_INC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)$(CHAMP_OPS_DIR).c $(HEADER_GAME)
	$(CC) -I $(INC_DIR) -I $(LIB_INC) $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME) $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
