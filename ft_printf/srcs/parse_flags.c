/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:47:53 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:48:00 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_flag(char c)
{
	if (c && pf_strchr(FLAGS_STR, c))
		return (1);
	return (0);
}

int				parse_flags(t_print *print, const char *format)
{
	int		count;
	char	c;

	count = 0;
	while (is_flag((c = format[count])))
	{
		if (c == '+')
			print->flags |= FLAG_PLUS;
		else if (c == '-')
			print->flags |= FLAG_MINUS;
		else if (c == ' ')
			print->flags |= FLAG_SPACE;
		else if (c == '#')
			print->flags |= FLAG_HASH;
		else if (c == '0')
			print->flags |= FLAG_NULL;
		else if (c == '\'')
			print->flags |= FLAG_APOSTROFE;
		count++;
	}
	if (print->flags & FLAG_PLUS)
		print->flags &= ~FLAG_SPACE;
	if (print->flags & FLAG_MINUS)
		print->flags &= ~FLAG_NULL;
	return (count);
}
