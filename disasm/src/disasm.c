/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:18:58 by damerica          #+#    #+#             */
/*   Updated: 2020/09/21 18:19:00 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		disasm_header(int wr_fd, int rd_fd)
{
	char	c;
	int		i;

	i = 0;
	while (i++ < 4)
		read(rd_fd, &c, 1);
	write_head_elem(".name \"", PROG_NAME_LENGTH, wr_fd, rd_fd);
	i = 0;
	while (i++ < 7)
		read(rd_fd, &c, 1);
	write_head_elem(".comment \"", COMMENT_LENGTH, wr_fd, rd_fd);
	write(wr_fd, "\n", 1);
	i = 0;
	while (i++ < 3)
		read(rd_fd, &c, 1);
}

void		disasm_cmd(int wr_fd, int rd_fd)
{
	int		ans;
	t_dis	dis;

	while ((ans = read(rd_fd, &dis.c, 1)) > 0)
	{
		dis.arg1 = 0;
		dis.arg2 = 0;
		dis.arg3 = 0;
		write(wr_fd, find_cmd(&dis), ft_strlen(dis.cmd_name));
		write(wr_fd, " ", 1);
		check_arg_type(&dis, rd_fd);
		write_arg(wr_fd, &dis, rd_fd, dis.arg1);
		if (dis.arg2)
		{
			write(wr_fd, ", ", 2);
			write_arg(wr_fd, &dis, rd_fd, dis.arg2);
		}
		if (dis.arg3)
		{
			write(wr_fd, ", ", 2);
			write_arg(wr_fd, &dis, rd_fd, dis.arg3);
		}
		write(wr_fd, "\n", 1);
	}
}
