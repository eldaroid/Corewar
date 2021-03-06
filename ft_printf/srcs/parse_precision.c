/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:48:21 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:48:28 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_va_prec(t_print *print, va_list *ptr, int prev_pow)
{
	int		res;

	res = va_arg(*ptr, int);
	if (res >= 0)
		print->precision = res;
	else
	{
		if (prev_pow != 0)
		{
			print->flags |= FLAG_MINUS;
			print->width = -res;
		}
		else
			print->precision = -1;
	}
	return (0);
}

int			parse_precision(t_print *print, const char *format, va_list *ptr)
{
	size_t			count;
	int				prev_pow;

	if (format[(count = 0)] == '.')
	{
		print->is_precision = 1;
		prev_pow = 0;
		while (format[++count] == '*' || pf_isdigit(format[count]))
		{
			if (format[count] == '*')
				prev_pow = get_va_prec(print, ptr, prev_pow);
			else
			{
				if (prev_pow == 0)
					print->precision = 0;
				print->precision *= 10;
				print->precision += (format[count] - '0');
				prev_pow = 1;
			}
		}
		if (print->precision == -1 && !(print->precision = 0))
			print->is_precision = 0;
	}
	return (count);
}
