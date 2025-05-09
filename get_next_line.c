/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:52:28 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/05/09 14:30:21 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static	char	*leftover;
	char			*buf;
	int				bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while ((leftover == NULL || !strchr_gnl(leftover, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), NULL);
	buf[bytes_read] = '\0';
	leftover = strjoin_gnl(leftover, buf);
	}
	line = extract_line(leftover);
	leftover = save_storage(leftover);
	return (free(buf), line);
}

	char	*extract_line(char *storage)
{
	size_t	mem_size;
	char	*find_line;
	char	*line;
	
	if (!storage || !*storage)
		return (NULL);
	find_line = storage;
	mem_size = 0;
	while (*find_line != '\n' && *find_line != '\0')
	{
		mem_size++;
		find_line++;
	}
	if (*find_line == '\n')
		mem_size++;
	line = malloc(mem_size + 1);
	if (!line)
		return (NULL);
	strlcpy_gnl(line, storage, mem_size + 1);
	return (line);
	
}

	char	*save_storage(char *storage)
{
	char	*new_line_pos;
	char	*new_storage;
	
	if (!storage)
		return (NULL);
	new_line_pos = strchr_gnl(storage, '\n');
	if (!new_line_pos)
	{
		free(storage);
		return (NULL);
	}
	new_line_pos++;
	new_storage = strdup_gnl(new_line_pos);
	free(storage);
	return (new_storage);	
}
