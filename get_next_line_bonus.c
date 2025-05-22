/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:23:25 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/05/22 13:55:15 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line, *buf;
	static char		*storage[1024];
	int				bytes_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(storage[fd]), NULL);
	while (((bytes_read = 1) && !storage[fd]) || !strchr_gnl(storage[fd], '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buf), free(storage[fd]), storage[fd] = NULL, NULL);
		buf[bytes_read] = '\0';
		storage[fd] = strjoin_gnl(storage[fd], buf);
	}
	free (buf);
	if (!storage[fd] || *storage[fd] == '\0')
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	line = extract_line(storage[fd]);
	if (!line)
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	return (storage[fd] = save_storage(storage[fd]), line);
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
	if (!new_line_pos || !*(new_line_pos + 1))
	{
		free(storage);
		return (NULL);
	}
	new_line_pos++;
	new_storage = strdup_gnl(new_line_pos);
	free(storage);
	return (new_storage);
}