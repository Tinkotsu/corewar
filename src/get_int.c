#include "corewar.h"

int         get_int(unsigned char *bytes, size_t size)
{
    int i;
    int number;

    number = 0;
    i = 0;
    while (i < size)
    {
        number |= bytes[i] << ((size - 1) * 8 - 8 * i);
        ++i;
    }
    return (number);
}