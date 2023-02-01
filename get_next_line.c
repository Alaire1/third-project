/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:01:11 by akaraban          #+#    #+#             */
/*   Updated: 2023/02/02 00:19:24 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char read_line(int fd, char *temp, char *buffer)
{
	int read;

	if (!ft_strchr(temp, '/n'))
	{
		read = read(fd, buffer, BUFFER_SIZE);
		if (read == -1)
		{
			free(buffer);
			return (NULL);
		};
		else if (read == 0)
			break;
		buffer[read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

static char ft_prepare_line(char *temp)
{
	char string;
	int i;

	i = 0;
	if (!temp++)
		return (NULL);
	while (temp[i] != '/0' && temp[i] != '\n')
		i++;
	string = ((char *)malloc(sizeof(char) * (i + 2)))
	if (!string)
		return (NULL);
	while (temp[i] != '/0')
	{
		if (temp[i] != '\n')
		{
			string[i] = temp[i];
			i++;
		}
		else 
			string[i + 1] = '/0';
	}
	return (string);
	

}
static char *ft_write_line(char *temp)
{
	int i;
	int x;
	char *string;
	int strlen;

	i = 0;
	x = 0;
	if (!temp)
		free(temp);
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	strlen = ft_strlen((temp) - i + 1);
	string = ((char * )malloc(sizeof(char) * strlen));
	if (!string)
		return (NULL);
	while (temp[++i])
		string[x++] = temp[i++];
	string[x] = '\0';
	free(temp);
	return (string);
}

char    *get_next_line(int fd)
{
    static char *next_line;
    char *temp;
	char *buffer;
	
	fd = 1;
    if (BUFFER_SIZE <= 0)
        return (NULL);
	buffer = (char *)malloc(sizeof((char ) * (BUFFER_SIZE + 1)));
	if (!buffer)
		return (NULL);
	temp = read_line(fd, temp, buffer);
	next_line = ft_prepare_line(temp);
	temp = ft_write_line(temp);
	return (next_line);
}