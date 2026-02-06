/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-a <agomez-a@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:39:49 by agomez-a          #+#    #+#             */
/*   Updated: 2026/02/06 17:48:01 by agomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
 #ifndef BUFFER_SIZE
  # define BUFFER_SIZE 42
 #endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*create_tmp(char *storage);
char	*fill_storage(int fd, char * storage);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*create_simple_line(char *pos, char *storage);
char	*concat_tmp_and_storage(char *tmp, char *storage, int include_newline);
char	*process_newline_found(char *tmp, char *storage, char **storage_ptr);
char	*handle_eof(char *tmp, char *storage);

#endif