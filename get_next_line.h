/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:41 by raphox            #+#    #+#             */
/*   Updated: 2023/12/18 16:21:17 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#ifndef _GET_NEXT_LINE_H

#define _GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd);
char	*read_from_file(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

#endif