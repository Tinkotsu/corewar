#include "game.h"

static int      get_arg_size(unsigned char arg, t_op *op)
{
    if (arg == 1)
        return (1);
    else if (arg == 2)
        return (op->dir_size == 0 ? 4 : 2);
    else if (arg == 4)
        return (IND_SIZE);
    return (0);
}

void            get_arg_bytes(char *bytes, int size, char *arena, int byte_pos)
{
    int i;

    i = 0;
    while (i < size)
    {
        bytes[i] = arena[(byte_pos + i) % MEM_SIZE];
        ++i;
    }
}

int     get_arg_pos(int arg_i, t_carriage *car, char *arena)
{
    int step;
    int i;

    step = car->op->arg_code + 1;
    i = 0;
    while (i < arg_i)
    {
        step += get_arg_size(car->args[i], car->op);
        ++i;
    }
    return (car->position + step);
}

int     check_pos(int pos)
{
    if (pos < 0)
        return ((MEM_SIZE - pos) % MEM_SIZE);
    else if (pos >= MEM_SIZE)
        return (pos % MEM_SIZE);
    return (pos);
}

void    get_args(int *args, t_carriage *car, t_cw *cw)
{
    int     i;
    int     pos;
    char    bytes[4];

    i = 0;
    while (i < car->op->args_amount)
    {
        pos = check_pos(get_arg_pos(i, car, cw->arena));
        get_arg_bytes(bytes, get_arg_size(car->args[i], car->op), cw->arena, pos);
        if (car->args[i] == 1) //T_REG
            args[i] = get_int(bytes, 1);
        else if (car->args[i] == 2) //T_DIR
            args[i] = get_int(bytes, car->op->dir_size == 0 ? 4 : 2);
        else if (car->args[i] == 4) //T_IND
            args[i] = get_int(bytes, 2);
        ++i;
    }
}