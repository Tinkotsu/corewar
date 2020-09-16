/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifran <ifran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:10:29 by eleonard          #+#    #+#             */
/*   Updated: 2019/10/22 19:44:32 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

# define CHAR_ARR (char []){"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890?.,=+ "}

typedef char*			(*t_s_func)(void *);

typedef	struct			s_func
{
	char				c;
	t_s_func			func;
}						t_func;

typedef union			u_cast_d
{
	long double			d;
	struct
	{
		unsigned long	mantisa : 64;
		unsigned long	exponent : 15;
		unsigned long	sign : 1;
	}					d_parts;
}						t_cast_d;

typedef struct			s_l_ar
{
	int					nb;
	int					carry;
	int					t;
	size_t				len;
	size_t				len1;
	size_t				len2;
}						t_l_ar;

typedef struct			s_pf
{
	va_list				ap;
	size_t				len;
	const char			*str;
	char				*types;
	t_func				func[10];
	char				*value;
	size_t				strlen;
	int					ret_value;
	char				t;
	char				*width;
	size_t				width_len;
	char				*p;
	size_t				p_len;
	size_t				p_size;
	int					flags_count;
	int					f_len;
	char				modf[2];
	int					flag_diez;
	int					flag_zero;
	int					flag_minus;
	int					flag_plus;
	int					flag_space;
	int					negative_p;
	size_t				fl_len;
	int					was_diez;
	size_t				ox;
	size_t				sign;
	long long			ta;
	t_cast_d			d;
	long double			even;
	int					first_len;
	int					exp;
	size_t				dot_pos;
	int					oversize;
	int					col;
	size_t				count_of_0;
	char				*pre;
	char				*cur;
	size_t				b;
}						t_pf;

int						ft_printf(const char *str, ...);
void					pf_flags(t_pf *s);
int						print_precision(t_pf *s);
void					pf_width(t_pf *s);
void					pf_precision(t_pf *s);
void					pf_modifier(t_pf *s);
void					pf_type(t_pf *s);
void					case_of_error(void);
t_pf					*initialize(const char *str);
void					re_initialize(t_pf *s);
void					func_arr(t_pf *s);
char					*pf_itoa(void *var);
char					*pf_hex(void *var);
char					*pf_bhex(void *var);
char					*pf_oct(void *var);
char					*pf_u(void *var);
void					pf_flag_diez(t_pf *s);
void					pf_flag_zero(t_pf *s);
void					pf_flag_minus(t_pf *s);
void					pf_flags_plus_and_space(t_pf *s);
void					pf_no_flags(t_pf *s);
void					pf_putvalue(t_pf *s);
void					pf_float(t_pf *s, long double n);
char					*long_add(char *pre, char *cur, int *oversize);
char					*long_mult(char *num1, char *num2);
size_t					find_last(char *str, size_t len, char c);
int						pf_colours(t_pf *s);
char					*to_binary(unsigned long int n);
char					*str_of_chars(size_t size, char c);
void					rounding(t_pf *s, size_t *index);
void					gain_str(char **arr_mult, t_pf *s);
size_t					ft_recursive_power(size_t nb, int power);
char					**gain_array(int exp, int nb, int max_power);
void					pf_dtoa(t_pf *s, size_t *index, int exp, char *mantisa);
void					pf_n(t_pf *s);
char					*morse(char *str);

#endif
