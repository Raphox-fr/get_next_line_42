/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:17:35 by raphox            #+#    #+#             */
/*   Updated: 2024/01/15 16:11:32 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all_line(char *line, int fd)
{
    char *buffer;
    int curseur;
    int size;

    curseur = 1;
    size = ft_strchr(line);
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    while(size > 0 && curseur != 0)
    {
        curseur = read(fd, buffer, BUFFER_SIZE);
        if (curseur == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[curseur] = '\0';
        line = ft_strjoin(line, buffer);
        size--;
    }
    free(buffer);
    return (line);
}

char    *get_res_line(char *line)
{
    int i;
    char *res_line;
    
    i = 0;
    if (!line[i])
        return (NULL);
    while (line[i] != '\n' && line[i])
    {
		i++;   
    }    
    res_line = malloc((ft_strlen(line) - i + 2) * sizeof(char));
    i = 0;
    while (line[i] != '\n' && line[i])
    {
        res_line[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
    {
        res_line[i] = line[i];
        i++;   
    }
    res_line[i] = '\0';
    return(res_line);       
}

char    *get_leftover_line(char *line)
{
    int i;
    int j;
    char *stock_leftover;

    j = 0;
    i = 0;
    while (line[i] != '\n' && line[i])
        i++;
    stock_leftover = malloc((ft_strlen(line) - i + 1) * (sizeof(char)));
    if (!stock_leftover)
        return(NULL);
    i++;
    while(line[i])
    {
        stock_leftover[j] = line[i];
        j++;
        i++;
    }
    stock_leftover[j] = '\0';
    free(line);
    return(stock_leftover);
}

char	*get_next_line(int fd)
{
    char *resleft_line;
    static char *line;

    line = get_all_line(line, fd);

    resleft_line = get_res_line(line);
    if (!resleft_line)
        return (NULL);
	line = get_leftover_line(line);
    return (line);
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
		printf("[%d]:%s", count, next_line);
		free(next_line);
		next_line = NULL;
	}
	printf("\n");
	close(fd);
	return (0);
}