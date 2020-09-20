#include "game.h"

static int  get_arg_size(t_op *op, int arg_i)
{
    if (op->args[arg_i] == 1)
        return (1);
    else if (op->args[arg_i] == 2)
        return (op->dir_size);
    else if (op->args[arg_i] == 4)
        return (IND_SIZE);
    return (0);
}


void        get_arg_bytes(char *bytes, int size, char *arena, int byte_pos)
{
    int i;

    i = 0;
    while (i < size)
    {
        bytes[i] = arena[(byte_pos + i) % MEM_SIZE];
        ++i;
    }
}

void        get_arg(int arg_i, t_carriage *car, char *arena, char *bytes)
{
    int     i;
    int     len;
    int     size;

    i = 0;
    len = 1 + car->op->arg_code;
    while (i < arg_i)
    {
        len += get_arg_size(car->op, i);
        ++i;
    }
    size = get_arg_size(car->op, arg_i);
    get_arg_bytes(bytes, size, arena, car->position + len);
 }