#include "game.h"

//todo: объединить эти две функции. возвращаем массив байтов.

void        get_arg_bytes(char *bytes, int size, char *pos)
{
    int i;

    i = 0;
    while (i < size)
    {
        bytes[i] = pos[i % MEM_SIZE];
        ++i;
    }
}

char        *get_arg_pos(int arg_i, t_carriage *car, char *arena)
{
    char    *pos;
    int     i;
    int     len;

    i = -1;
    len = 1 + car->op->arg_code;
    while (i < arg_i)
    {
        if (car->op->args[i] == 1)
            ++len;
        else if (car->op->args[i] == 2)
            len += car->op->dir_size;
        else if (car->op->args[i] == 4)
            len += 4;
        ++i;
    }
    pos = &arena[(car->position + len) % MEM_SIZE];
    return (pos);
}