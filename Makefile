COREWAR_DIR = ./corewar/
ASM_DIR = ./asm/
DISASM_DIR = ./disasm/

all: lib asm corewar disasm

asm: lib
	make asm -C $(ASM_DIR)

corewar: lib
	make corewar -C $(COREWAR_DIR)

disasm: lib
	make disasm -C $(DISASM_DIR)

lib:
	make -C libft/

clean:
	make clean -C libft/
	make clean -C $(ASM_DIR)
	make clean -C $(COREWAR_DIR)
	make clean -C $(DISASM_DIR)

fclean:
	make fclean -C libft/
	make fclean -C $(ASM_DIR)
	make fclean -C $(COREWAR_DIR)
	make fclean -C $(DISASM_DIR)

re: fclean all

.PHONY: all asm corewar disasm lib clean fclean re

