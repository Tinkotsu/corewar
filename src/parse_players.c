#include "corewar.h"
#include <stdio.h>

static unsigned int          read_ints(int fd, size_t size)
{
    char        buf[size];
    unsigned int         res;

    if (read(fd, buf, size) != size)
        error("Failed reading");
    res = get_int(buf, size);
    printf("my magic = %d\nreal magic = %d\n", res, (int)COREWAR_EXEC_MAGIC);
    return (res);
}

static void         read_chars(int fd, unsigned int size, char *dest, int last)
{
    char        buf[size + 1];
    int         i;

    i = 0;
    if (read(fd, buf, size) != size)
        error("Failed reading");
    while (i < size)
    {
        dest[i] = buf[i];
        ++i;
    }
    if (last)
        if (read(fd, buf, 1))
            error("Champion size is not the same as declared");
}

static void         check_nulls(int fd, size_t size)
{
    char    buf[size];
    int     i;

    i = 0;
    if (read(fd, buf, size) != size)
        error("Failed reading");
    while (i < size)
    {
        if (buf[i])
            error("Skipped nulls checkpoint");
        ++i;
    }
}

static void         read_player(int fd, t_player *player)
{
    if (read_ints(fd, sizeof(int)) != COREWAR_EXEC_MAGIC)
        error("Wrong magic header");
    read_chars(fd, PROG_NAME_LENGTH, player->name, 0);
    check_nulls(fd, sizeof(int));
    player->exec_size = read_ints(fd, sizeof(int));
    if (player->exec_size < 0 || player->exec_size > CHAMP_MAX_SIZE)
        error("Wrong champion size");
    read_chars(fd, COMMENT_LENGTH, player->comment, 0);
    check_nulls(fd, sizeof(int));
    player->exec_code = (char *)malloc(player->exec_size);
    if (!player->exec_code)
        error("Memory error");
    ft_bzero(player->exec_code, player->exec_size);
    read_chars(fd, player->exec_size, player->exec_code, 1);
}

void            parse_players(t_cw *cw)
{
    int i;
    int fd;

    i = 0;
    while (i < cw->players_amount)
    {
        char *name = cw->players[i]->filename;
        fd = open(name, O_RDONLY);
        if (fd < 0)
            error("Unable to open a file");
        read_player(fd, cw->players[i]);
        close(fd);
        ++i;
    }
}