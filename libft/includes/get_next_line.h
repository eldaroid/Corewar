/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:04:29 by fgracefo          #+#    #+#             */
/*   Updated: 2020/12/02 16:01:44 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE (524288)

typedef struct	s_fddata
{
	int				fd;
	int				eof;
	char			*buf;
	char			*str;
	unsigned long	str_len;
	unsigned long	str_size;
}				t_fddata;

int				get_next_line(const int fd, char **line);

#endif
