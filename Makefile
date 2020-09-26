COREWAR_DIR = ./corewar/
ASM_DIR = ./asm/
DISASM_DIR = ./disasm/

all: asm corewar disasm

asm:
	make -C $(ASM_DIR)

corewar:
	make -C $(COREWAR_DIR)

disasm:
	make -C $(DISASM_DIR)

clean:
	make clean -C $(ASM_DIR)
	make clean -C $(COREWAR_DIR)
	make clean -C $(DISASM_DIR)

fclean:
	make fclean -C $(ASM_DIR)
	make fclean -C $(COREWAR_DIR)
	make fclean -C $(DISASM_DIR)

re: fclean all

.PHONY: all clean fclean re

