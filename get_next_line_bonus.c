/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-a <agomez-a@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:32:42 by agomez-a          #+#    #+#             */
/*   Updated: 2026/02/09 12:59:34 by agomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];	
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage[fd] == NULL)
		storage[fd] = fill_storage(fd, storage[fd]);
	tmp = NULL;
	if (storage[fd] != NULL)
	{
		while (!(ft_strchr(storage[fd], '\n')))
		{
			if (tmp == NULL)
				tmp = create_tmp(storage[fd]);
			free(storage[fd]);
			storage[fd] = fill_storage(fd, storage[fd]);
			if (!storage[fd] || storage[fd][0] == '\0')
				return (handle_eof(tmp, &storage[fd]));
			if (ft_strchr(storage[fd], '\n'))
				return (process_newline_found(tmp, storage[fd], &storage[fd]));
			tmp = concat_tmp_and_storage(tmp, storage[fd], 0);
		}
		return (process_newline_found(tmp, storage[fd], &storage[fd]));
	}
	return (NULL);
}

char	*create_tmp(char *storage)
{
	int		i;
	int		len;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	while (storage[i] != '\0')
	{
		count++;
		i++;
	}
	len = count + 1;
	tmp = malloc(len);
	if (!tmp)
		return (NULL);
	i = 0;
	while (storage[i] != '\0')
	{
		tmp[i] = storage[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*fill_storage(int fd, char *storage)
{
	int			bytes_leidos;
	char		buffer[BUFFER_SIZE + 1];

	bytes_leidos = read(fd, buffer, BUFFER_SIZE);
	if (bytes_leidos == -1)
		return (free(storage), storage = NULL, NULL);
	buffer[bytes_leidos] = '\0';
	storage = malloc(bytes_leidos + 1);
	if (!storage)
		return (NULL);
	ft_memcpy(storage, buffer, bytes_leidos);
	storage[bytes_leidos] = '\0';
	return (storage);
}

char	*concat_tmp_and_storage(char *tmp, char *storage, int include_newline)
{
	char	*line;
	char	*pos;

	if (include_newline == 1)
	{
		pos = ft_strchr(storage, '\n');
		line = malloc(ft_strlen(tmp) + (pos - storage) + 2);
		if (!line)
			return (NULL);
		ft_memcpy(line, tmp, ft_strlen(tmp));
		if (pos - storage > 0)
			ft_memcpy(line + ft_strlen(tmp), storage, pos - storage);
		line[ft_strlen(tmp) + (pos - storage)] = '\n';
		line[ft_strlen(tmp) + (pos - storage) + 1] = '\0';
	}
	else
	{
		line = malloc(ft_strlen(tmp) + ft_strlen(storage) + 1);
		if (!line)
			return (NULL);
		ft_memcpy(line, tmp, ft_strlen(tmp));
		ft_memcpy(line + ft_strlen(tmp), storage, ft_strlen(storage) + 1);
	}
	free(tmp);
	return (line);
}

char	*handle_eof(char *tmp, char **storage_ptr)
{
	if (tmp && tmp[0] != '\0')
		return (tmp);
	free(tmp);
	if (*storage_ptr)
	{
		free(*storage_ptr);
		*storage_ptr = NULL;
	}
	return (NULL);
}
