/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:49:44 by gdorcas           #+#    #+#             */
/*   Updated: 2020/12/01 18:49:51 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	pf_bzero(void *s, size_t n)
{
	unsigned char	*sc;

	sc = (unsigned char *)s;
	while ((size_t)sc % sizeof(unsigned long) && n)
	{
		*sc++ = 0;
		n--;
	}
	while (n >= sizeof(unsigned long))
	{
		*(unsigned long *)sc = 0;
		sc += sizeof(unsigned long);
		n -= sizeof(unsigned long);
	}
	while (n)
	{
		*sc++ = 0;
		n--;
	}
}

char	*pf_strchr(const char *s, int c)
{
	size_t	length;
	size_t	count;

	count = 0;
	length = 0;
	while (s[length] != '\0')
		length++;
	length++;
	while (count < length)
	{
		if (s[count] == c)
			return (char *)(s + count);
		count++;
	}
	return (NULL);
}

size_t	pf_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int		pf_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
