/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-a <agomez-a@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:32:45 by agomez-a          #+#    #+#             */
/*   Updated: 2026/02/06 17:36:45 by agomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (unsigned char)(c))
		return ((char *)(s + i));
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p_dest;
	const char	*p_src;

	p_dest = (char *)dest;
	p_src = (const char *)src;
	i = 0;
	while (i < n && (src || dest))
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

char	*create_simple_line(char *pos, char *storage)
{
	char	*line;
	
	line = malloc((pos - storage) + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, storage, pos - storage);
	line[pos - storage] = '\n';
	line[(pos - storage) + 1] = '\0';
	return (line);
}

char	*process_newline_found(char *tmp, char *storage, char **storage_ptr)
{
	char	*line;
	char	*pos;
	char	*tmp2;

	pos = ft_strchr(storage, '\n');
	if (tmp != NULL)
		line = concat_tmp_and_storage(tmp, storage, 1);
	else
		line = create_simple_line(pos, storage);
	tmp2 = malloc(ft_strlen(pos + 1) + 1);
	if (!tmp2)
		return (NULL);
	ft_memcpy(tmp2, pos + 1, ft_strlen(pos + 1) + 1);
	free(storage);
	*storage_ptr = tmp2;
	return (line);
}
