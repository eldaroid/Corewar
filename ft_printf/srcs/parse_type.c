/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:49:14 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:49:21 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_type(t_print *print, const char *format)
{
	char c;

	if ((c = *format))
	{
		print->type = c;
		if (pf_strchr(DEPRECATED_STR, c))
		{
			print->type = pf_tolower(c);
			print->lenmod = LENMOD_L;
		}
		return (1);
	}
	return (0);
}
