/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:28:53 by eklompus          #+#    #+#             */
/*   Updated: 2020/12/01 18:26:49 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "libft.h"

void	print_sdl_error(const char *err)
{
	ft_putstr("SDL Error: ");
	ft_putendl(err);
}
