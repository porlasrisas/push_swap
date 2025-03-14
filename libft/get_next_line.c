/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:10:13 by guigonza          #+#    #+#             */
/*   Updated: 2024/10/30 20:12:30 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_error(char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

static char	*ft_reading_saving(int fd, char *buffer)
{
	char		*tmp;
	ssize_t		readed;

	if (!buffer)
		buffer = ft_strdup_gnl("");
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_error(buffer));
	while (buffer && !ft_strchr_gnl(buffer, '\n'))
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed < 0)
			return (ft_error(buffer), ft_error(tmp));
		if (readed == 0)
		{
			if (buffer[0] == '\0')
				return (ft_error(tmp), buffer);
			break ;
		}
		tmp[readed] = '\0';
		buffer = ft_gnljoin(buffer, tmp);
		if (!buffer)
			return (ft_error(buffer));
	}
	return (ft_error(tmp), buffer);
}

static char	*ft_get_lines(char **buffer)
{
	char	*line;
	char	*newline;
	char	*remaining;

	if (!buffer || !*buffer)
		return (NULL);
	newline = ft_strchr_gnl(*buffer, '\n');
	if (newline)
	{
		line = ft_substr(*buffer, 0, newline - *buffer + 1);
		remaining = ft_strdup_gnl(newline + 1);
		free(*buffer);
		*buffer = remaining;
		if (!line)
			return (ft_error(line));
	}
	else
	{
		line = ft_strdup_gnl(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffers[fd] = ft_reading_saving(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = ft_get_lines(&buffers[fd]);
	if (line && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
