/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:41 by raphox            #+#    #+#             */
/*   Updated: 2024/01/11 17:21:12 by raphox           ###   ########.fr       */
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


char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen_perso(char *str);

#endif