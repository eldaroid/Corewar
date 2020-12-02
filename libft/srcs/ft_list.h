/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:23:30 by fgracefo          #+#    #+#             */
/*   Updated: 2020/11/01 20:24:47 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	int				x;

	int				y;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

#endif
