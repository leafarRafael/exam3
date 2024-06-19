/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:18:25 by rbutzke           #+#    #+#             */
/*   Updated: 2024/06/19 13:22:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*add_back(char *heap, char *stack);
static int	find_n(char *str);
static char	*cpy(char *str);
static int	len(char *str);
static void replace(char *str, int i);

char	*get_next_line(int fd)
{
	static char	*line;
	char		buf[BUFFER_SIZE +1];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line);	
		return (NULL);
	}
	if (line)
	{
		if (find_n(line))
			return (cpy(line));
	}
	i = read(fd, buf, BUFFER_SIZE);
	if (i)
	{
		buf[i] = '\0';
		line = add_back(line, buf);
		if (find_n(line))
			return (cpy(line));
		else
			return (get_next_line(fd));
	}
	return (cpy(line));
}

static char	*cpy(char *str)
{
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	i = len(str);
	line = malloc(sizeof (char) * (i+1));
	if (str[0] == '\0' && i == 1)
	{
		line[0] = '\0';
		return (line);
	}
	if (!line)
		return (NULL);
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		if (line[i] ==  '\n')
			break ;
		i++;
	}
	if (line[i] ==  '\n')
		i++;
	replace(str, i);
	line[i] = '\0';
	return (line);
}

static char	*add_back(char *heap, char *stack)
{
	int		size;
	char	*new;
	char	*help;
	char	*temp;

	size = len(heap) + len(stack) +1;
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	help = new;
	temp = heap;
	if (heap)
	{
		while (*temp)
			*help++ = *temp++;
	}
	if (stack)
	{
		while (*stack)
			*help++ = *stack++;
	}
	*help = '\0';
	if (heap)
	{
		free(heap);
		heap = (NULL);
	}
	return (new);
}

static int	len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '\0')
		return (1);
	while (str[i])
		i++;
	return (i);
}

static int	find_n(char *str)
{
	int	i;
	int	find;

	i = 0;
	find = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			find++;
		i++;
	}
	return (find);	
}

static void replace(char *str, int i)
{
	int	x;

	if (!str)
		return ;
	x = 0;
	if (str[i] == '\0')
	{
		str[x] = str[i];
		return ;
	}
	while (str[i])
	{
		str[x] = str[i];
		x++;
		i++;
	}
	while (str[x])
	{
		str[x] = '\0';
		x++;
	}
}
