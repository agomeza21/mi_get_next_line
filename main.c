/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-a <agomez-a@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:57:54 by agomez-a          #+#    #+#             */
/*   Updated: 2026/02/06 17:27:23 by agomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int count = 1;

    fd = open("test4.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error abriendo archivo\n");
        return (1);
    }
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea %d: [%s]\n", count, line);
        free(line);
        count++;
    }
    
    close(fd);
    return (0);
}
/*
int main(void)
{
    char *line;
    int count = 1;

    printf("Escribe líneas (Ctrl+D para terminar):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Leído línea %d: [%s]\n", count, line);
        free(line);
        count++;
    }
    
    return (0);
}

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test3.txt", O_RDONLY);
    
    if (fd1 == -1 || fd2 == -1)
    {
        printf("Error abriendo archivos\n");
        return (1);
    }

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    printf("FD1: [%s]\n", line1);
    printf("FD2: [%s]\n", line2);
    free(line1);
    free(line2);

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    printf("FD1: [%s]\n", line1);
    printf("FD2: [%s]\n", line2);
    free(line1);
    free(line2);

    close(fd1);
    close(fd2);
    return (0);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("test4.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);
    }
    close(fd);
    return (0);
}*/
