#include "game.h"


static void             get_op_args(char byte, unsigned char *args)
{
    int i;

    i = 0;
    while (i < 4)
    {
        args[i] = (byte >> (6 - 2 * i)) & 00000011;
        if (args[i] == 3)
            args[i] = 4;
        ++i;
    }
}

static int              check_reg(t_carriage *car, char *arena)
{
    char reg_byte;

    reg_byte = arena[(car->position + car->step - 1) % MEM_SIZE];
    if (car->reg[0] != -(int)reg_byte)
        return (0);
    return (1);
}

static int              check_args(t_carriage *car, unsigned char *args, char *arena)
{
    int     i;

    if (!car->op->arg_code)
    {
        car->step += car->op->dir_size;
        return (1);
    }
    i = 0;
    while (i < car->op->args_amount)
    {
        if (args[i] == 1)
            ++car->step;
        else if (args[i] == 2)
            car->step += car->op->dir_size;
        else if (args[i] == 4)
            car->step += 4;
        if (!(car->op->args[i] & args[i]) ||
            (args[i] == 1 && !check_reg(car, arena)))
            return (0);
        ++i;
    }
    return (1);
}

int                     validate_op(t_cw *cw, t_carriage *car)
{
    unsigned char   args[4];

    if (car->op->arg_code)
    {
        get_op_args(cw->arena[(car->position + car->step) % MEM_SIZE], args);
        ++car->step;
    }
    if (!check_args(car, args, cw->arena))
        return (0);
    return (1);
}
