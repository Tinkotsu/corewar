#include "game.h"


static void             get_op_args(unsigned char byte, unsigned char *args)
{
    int i;
    int shift;
    i = 0;

    while (i < 4)
    {
        shift = 6 - 2 * i;
        args[i] = (byte & (3 << shift)) >> shift;
        int n = args[i];
        if (args[i] == 3)
            args[i] = 4;
        ++i;
    }
}

static int              check_reg(t_carriage *car, unsigned char *arena)
{
    unsigned char reg_byte;

    reg_byte = arena[(car->position + car->step - 1) % MEM_SIZE];
    if (reg_byte < 1 || reg_byte > 16)
        return (0);
    return (1);
}

static int              check_args(t_carriage *car,
                                   unsigned char *args, unsigned char *arena)
{
    int     i;

    if (!car->op->arg_code)
    {
        car->step += car->op->dir_size == 0 ? 4 : 2;
        return (1);
    }
    i = 0;
    while (i < car->op->args_amount)
    {
        if (args[i] == 1)
            ++car->step;
        else if (args[i] == 2)
            car->step += car->op->dir_size == 0 ? 4 : 2;
        else if (args[i] == 4)
            car->step += 4;
        if (!(car->op->args[i] & args[i]) ||
            (args[i] == 1 && !check_reg(car, arena)))
            return (0);
        ++i;
    }
    while (i < 4)
        if (args[i++])
            return (0);
    return (1);
}

int                     validate_op(t_cw *cw, t_carriage *car)
{
    if (car->op->arg_code)
    {
        get_op_args(cw->arena[(car->position + 1) % MEM_SIZE], car->args);
        ++car->step;
    }
    if (!check_args(car, car->args, cw->arena))
        return (0);
    return (1);
}
