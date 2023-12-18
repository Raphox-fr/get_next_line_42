/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:35 by raphox            #+#    #+#             */
/*   Updated: 2023/12/18 16:58:34 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(int fd)
{
	int		bytes_read;
	char	*stack_buffer;
    static int count = 0;
    
    
    printf("ft_calloc#[%d]---", count++);
    stack_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	
    if (stack_buffer == NULL)
		return (NULL);
	
    bytes_read = read(fd, stack_buffer, BUFFER_SIZE);
	
    if (bytes_read <= 0)
    {
        free(stack_buffer);
		return (NULL);
    }
    return (stack_buffer);
}

char	*get_next_line(int fd)
{
    char *the_ultimate_buffer;
    
    the_ultimate_buffer = read_from_file(fd);
    
    return(the_ultimate_buffer);
}



int	main(void)
{
	int fd;
	char *next_line;
	int count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free(next_line);
		next_line = NULL;
	}
    printf("\n");
	close(fd);
	return (0);
}