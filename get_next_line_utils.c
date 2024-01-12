/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:15:46 by raphox            #+#    #+#             */
/*   Updated: 2024/01/11 23:15:34 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*sexy;

	i = 0;
	sexy = s;
	while (sexy[i])
	{
		if (sexy[i] == (unsigned char)c)
		{
			return (((char *)sexy) + i);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_strlen_perso(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_blyat_strlcpy(char *blyat, char *dst, const char *src,
		size_t dstsize)
{
	size_t	i;
	int		l;

	l = 0;
	if (blyat == NULL)
		return (NULL);
	if (!dst || !src)
		return (0);
	i = ft_strlen(blyat);
	if (dstsize != 0)
	{
		while (src[l] != '\0')
		{
			blyat[i] = src[l];
			i++;
			l++;
		}
		blyat[i] = '\0';
	}
	return (blyat);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*src;
	int		count1;
	int		count2;
	char	*suka;

	dest = (char *)s1;
	src = (char *)s2;
	count1 = ft_strlen_perso(dest);
	count2 = ft_strlen_perso(src);
	suka = malloc((sizeof(char)) * (count1 + count2) + 1);
	if (suka == NULL)
		return (NULL);
	suka[0] = '\0';
	suka = ft_blyat_strlcpy(suka, &dest[0], dest, count1);
	suka = ft_blyat_strlcpy(suka, &dest[count1], src, count2);
	return (suka);
}