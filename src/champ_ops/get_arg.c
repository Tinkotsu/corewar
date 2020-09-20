#include "game.h"

static int  get_arg_size(char arg, t_op *op)
{
    if (arg == 1)
        return (1);
    else if (arg == 2)
        return (op->dir_size == 0 ? 4 : 2);
    else if (arg == 4)
        return (IND_SIZE);
    return (0);
}

void        get_arg_bytes(char *bytes, int size, char *arena, int byte_pos)
{
    int i;

    i = 0;
    if (byte_pos < 0)
        byte_pos = (MEM_SIZE - byte_pos) % MEM_SIZE;
    while (i < size)
    {
        bytes[i] = arena[(byte_pos + i) % MEM_SIZE];
        ++i;
    }
}

void        get_arg(int arg_i, t_carriage *car,
                    char *arena, char *bytes)
{
    int     i;
    int     len;
    int     size;

    i = 0;
    len = 1 + car->op->arg_code;
    while (i < arg_i)
    {
        len += get_arg_size(car->args[i], car->op);
        ++i;
    }
    size = get_arg_size(car->args[i], car->op);
    get_arg_bytes(bytes, size, arena, car->position + len);
 }

 int    get_ind_value(t_carriage *car, char *arena, char *ind_bytes, int l_op)
 {
    int res;
    int ind_pos;

    res = get_int(ind_bytes, IND_SIZE);
    if (l_op)
        ind_pos = (car->position + res) % MEM_SIZE;
    else
        ind_pos = ((car->position + res) % IDX_MOD) % MEM_SIZE;
    get_arg_bytes(ind_bytes, 4, arena, ind_pos);
    res = get_int(ind_bytes, 4);
    return (res);
 }