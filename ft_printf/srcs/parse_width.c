/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:49:35 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:49:41 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_width(t_print *print, const char *format, va_list *ptr)
{
	int			count;
	int			f;

	count = 0;
	f = 1;
	while (format[count] == '*' || pf_isdigit(format[count]))
	{
		if (format[count] == '*' && (f = 1))
		{
			if ((print->width = va_arg(*ptr, int)) < 0)
			{
				print->width = -print->width;
				print->flags |= FLAG_MINUS;
			}
		}
		else
		{
			if (f && !(f = 0))
				print->width = 0;
			print->width *= 10;
			print->width += (format[count] - '0');
		}
		count++;
	}
	return (count);
}
