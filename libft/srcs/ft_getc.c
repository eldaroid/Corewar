/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmetallo <dmetallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:35:19 by dmetallo          #+#    #+#             */
/*   Updated: 2020/12/02 15:35:24 by dmetallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_getc(int fd)
{
	char	c;
	int		ret;

	ret = read(fd, &c, 1);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (FT_EOF);
	return (c);
}
