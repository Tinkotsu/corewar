#include "corewar.h"

static void     ft_printhex(int n)
{
    int c;

    if (n >= 16)
        ft_printhex(n / 16);
    c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
    ft_putchar(c);
}

static void     print_column(int counter)
{
    int i;

    ft_putstr("0x");
    i = 0x1000;
    while (i > counter + 1)
    {
        ft_putchar('0');
        i /= 16;
    }
    ft_printhex(counter);
    ft_putstr(" : ");
    i = 0;
}

void	        display_arena(char *arena, int octets_num)
{
    int		        counter;
    int		        i;
    unsigned char   c;

    counter = 0;
    while (counter < MEM_SIZE)
    {
        print_column(counter);
        i = 0;
        while (i < octets_num)
        {
            c = (unsigned char)*arena;
            if (c < 16)
                ft_putchar('0');
            ft_printhex(c);
            ft_putchar(' ');
            arena++;
            i++;
        }
        ft_putchar('\n');
        counter += octets_num;
    }
}