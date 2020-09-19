#include "game.h"

void (*champ_ops[16])(t_carriage *car, t_cw *cw) = {
        &ch_live
        /*
        &ch_ld,
        &ch_st,
        &ch_add,
        &ch_sub,
        &ch_and,
        &ch_or,
        &ch_xor,
        &ch_zjmp,
        &ch_ldi,
        &ch_sti,
        &ch_fork,
        &ch_lld,
        &ch_lldi,
        &ch_lfork,
        &ch_aff*/
};