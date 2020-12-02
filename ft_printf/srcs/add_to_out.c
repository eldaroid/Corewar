/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:46:23 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:46:25 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flush_buf(t_print *print)
{
	print->write_func(&print->write_param, print->buf, print->buf_len);
	print->buf_len = 0;
}

int		add_to_out(t_print *print, char c)
{
	print->buf[print->buf_len++] = c;
	if (print->buf_len >= sizeof(print->buf))
		flush_buf(print);
	return (1);
}

int		addw_to_out(t_print *print, wint_t wc)
{
	int		writed;

	writed = 0;
	if (wc < 0x80)
		writed += add_to_out(print, wc);
	else if (wc >= 0x80 && wc < 0x800)
	{
		writed += add_to_out(print, 0xC0 + wc / 64);
		writed += add_to_out(print, 0x80 + wc % 64);
	}
	else if (wc >= 0x800 && wc < 0x10000)
	{
		writed += add_to_out(print, 0xE0 + wc / 4096);
		writed += add_to_out(print, 0x80 + (wc / 64) % 64);
		writed += add_to_out(print, 0x80 + wc % 64);
	}
	else if (wc >= 0x10000 && wc < 0x110000)
	{
		writed += add_to_out(print, 0xF0 + wc / 262144);
		writed += add_to_out(print, 0x80 + (wc / 4096) % 64);
		writed += add_to_out(print, 0x80 + (wc / 64) % 64);
		writed += add_to_out(print, 0x80 + wc % 64);
	}
	return (writed);
}
