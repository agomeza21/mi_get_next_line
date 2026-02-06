/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-a <agomez-a@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:32:42 by agomez-a          #+#    #+#             */
/*   Updated: 2026/02/06 14:19:44 by agomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;	
	char		*line;
	char		*tmp;
	char		*pos;
	char		*tmp2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage == NULL)
	{
		storage = fill_storage(fd, storage);
	}
	tmp = NULL;
	line = NULL;
	if (storage != NULL)
	{
		while (!(ft_strchr(storage, '\n')))
		{
			if (tmp == NULL)
				tmp = create_line(storage);
			free(storage);
			storage = fill_storage(fd, storage);
			if (!storage || storage[0] == '\0')
			{
				if (tmp && tmp[0] != '\0')
					return (tmp);
				free(tmp);
				if (storage)
					free(storage);
				return (NULL);
			}
			if (ft_strchr(storage, '\n'))
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
				free(tmp);
				tmp2 = malloc(ft_strlen(pos + 1) + 1);
				ft_memcpy(tmp2, pos + 1, ft_strlen(pos + 1) + 1);
				free (storage);
				storage = tmp2;
				return (line);
			}
			else
			{
				line = malloc(ft_strlen(tmp) + ft_strlen(storage) + 1);
				if (!line)
					return (NULL);
				ft_memcpy(line, tmp, ft_strlen(tmp));
				ft_memcpy(line + ft_strlen(tmp), storage, ft_strlen(storage) + 1);
				free (tmp);
    			tmp = line;
			}
		}
		while (ft_strchr(storage, '\n'))
		{
			pos = ft_strchr(storage, '\n');
			if (tmp != NULL)
			{
				line = malloc(ft_strlen(tmp) + (pos - storage) + 2);
				if (!line)
					return (NULL);
				ft_memcpy(line, tmp, ft_strlen(tmp));
				if (pos - storage > 0)
					ft_memcpy(line + ft_strlen(tmp), storage, pos - storage);
				line[ft_strlen(tmp) + (pos - storage)] = '\n';
				line[ft_strlen(tmp) + (pos - storage) + 1] = '\0';
				free(tmp);
			}
			else
			{
				line = malloc((pos - storage) + 2);
				if (!line)
					return (NULL);
				ft_memcpy(line, storage, pos - storage);
				line[pos - storage] = '\n';
				line[(pos - storage) + 1] = '\0';
			}
			tmp2 = malloc(ft_strlen(pos + 1) + 1);
			ft_memcpy(tmp2, pos + 1, ft_strlen(pos + 1) + 1);
			free (storage);
			storage = tmp2;
			return (line);
		}
	}
	return (line);
}

char	*create_line(char *storage)
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

char	*fill_storage(int fd, char * storage)
{
	int			bytes_leidos;
	char		buffer[BUFFER_SIZE + 1];

	bytes_leidos = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_leidos] = '\0';
	if (bytes_leidos == -1)
		return (free(storage), storage = NULL, NULL);
	storage = malloc(bytes_leidos + 1);
	if (!storage)
		return (NULL);
	ft_memcpy(storage, buffer, bytes_leidos);
	storage[bytes_leidos] = '\0';
	return (storage);
}
