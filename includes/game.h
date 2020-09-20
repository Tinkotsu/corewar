#ifndef GAME_H
# define GAME_H

# include "corewar.h"

extern void (*champ_ops[16])(t_carriage *car, t_cw *cw);


void            get_arg(int arg_i, t_carriage *car,
                        unsigned char *arena, unsigned char *bytes);
void            get_arg_bytes(unsigned char *bytes, int size,
                              unsigned char *arena, int byte_pos);
int             get_ind_value(t_carriage *car, unsigned char *arena,
                              unsigned char *ind_bytes, int l_op);
void            ch_live(t_carriage *car, t_cw *cw);
void            ch_ld(t_carriage *car, t_cw *cw);
void            ch_st(t_carriage *car, t_cw *cw);
void            ch_add(t_carriage *car, t_cw *cw);
void            ch_sub(t_carriage *car, t_cw *cw);
void            ch_and(t_carriage *car, t_cw *cw);
void            ch_or(t_carriage *car, t_cw *cw);
void            ch_xor(t_carriage *car, t_cw *cw);
void            ch_zjmp(t_carriage *car, t_cw *cw);
void            ch_ldi(t_carriage *car, t_cw *cw);
void            ch_sti(t_carriage *car, t_cw *cw);
void            ch_fork(t_carriage *car, t_cw *cw);
void            ch_lld(t_carriage *car, t_cw *cw);
void            ch_lldi(t_carriage *car, t_cw *cw);
void            ch_lfork(t_carriage *car, t_cw *cw);
void            ch_aff(t_carriage *car, t_cw *cw);

#endif