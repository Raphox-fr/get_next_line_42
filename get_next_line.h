/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:41 by raphox            #+#    #+#             */
/*   Updated: 2024/01/15 16:05:10 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#ifndef _GET_NEXT_LINE_H

# define _GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_all_line(char *line, int fd);

int     ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);

#endif