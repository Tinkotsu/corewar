#include "corewar.h"

int         get_int(char *bytes, size_t size)
{
    int i;
    int number;
    int shift;

    number = 0;
    i = 0;
    while (i < size)
    {
        shift = (size - 1) * 8 - 8 * i;
        number |= bytes[i] << shift;
        ++i;
    }
    return (number);
}