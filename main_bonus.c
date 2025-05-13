/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:27:39 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/05/13 12:28:26 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s file1 file2 file3\n", argv[0]);
        return 1;
    }

    int fds[3] = {
        open(argv[1], O_RDONLY),
        open(argv[2], O_RDONLY),
        open(argv[3], O_RDONLY)
    };
    for (int i = 0; i < 3; ++i)
    {
        if (fds[i] < 0)
        {
            perror(argv[i+1]);
            return 1;
        }
    }

    char *line;
    int  active = 3;

    while (active > 0)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (fds[i] < 0)
                continue;

            line = get_next_line(fds[i]);
            if (line)
            {
                printf("File%d: %s", i + 1, line);
                free(line);
            }
            else
            {
                close(fds[i]);
                fds[i] = -1;
                --active;
            }
        }
    }

    return 0;
}
