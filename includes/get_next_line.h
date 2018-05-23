/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvautrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:02:54 by cvautrai          #+#    #+#             */
/*   Updated: 2018/03/01 13:19:04 by cvautrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define FD_MAX 1024
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);

#endif
