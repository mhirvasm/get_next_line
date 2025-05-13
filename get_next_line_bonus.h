/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:10:54 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/05/13 12:11:48 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <fcntl.h> //open()
#include <unistd.h> // read() and close ()
#include <stdlib.h> //TESTING DELETE THIS 

// Main function 
char			*get_next_line(int fd);

// Utility functions
char			*strjoin_gnl(char *s1, char *s2);
char			*strchr_gnl(const char *s, int c);
size_t			strlen_gnl(const char *s);
char			*extract_line(char *storage);
char			*save_storage(char *storage);
size_t			strlcpy_gnl(char *dst, const char *src, size_t size);
char			*strdup_gnl(const char *s);

#endif