/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paddings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:46:11 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:46:13 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_pre_paddings(t_print *print)
{
	int		writed;
	int		count;

	count = -1;
	writed = 0;
	if (!(print->flags & FLAG_MINUS) && !(print->flags & FLAG_NULL))
	{
		while ((++count + print->str_len + print->pre_len) < print->width)
			writed += add_to_out(print, ' ');
	}
	writed += add_prefix(print);
	if (!(print->flags & FLAG_MINUS) && (print->flags & FLAG_NULL))
	{
		while ((++count + print->str_len + print->pre_len) < print->width)
			writed += add_to_out(print, '0');
	}
	print->pad_len += writed;
	return (writed);
}

int		add_post_paddings(t_print *print)
{
	int		writed;
	int		count;

	count = print->str_len + print->pre_len;
	writed = 0;
	if (print->flags & FLAG_MINUS)
	{
		while (++count <= print->width)
			writed += add_to_out(print, ' ');
	}
	print->pad_len += writed;
	return (writed);
}
