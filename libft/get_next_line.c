/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <klaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:42:48 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/24 16:19:57 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		line_in_tail(char **tail, char **line)
{
	int		i;
	char	*fortail;
	char	*string;

	i = 0;
	string = *tail;
	while (string[i])
	{
		if (string[i] == '\n')
		{
			*line = ft_strsub(string, 0, i);
			fortail = ft_strsub(string, i + 1, (ft_strlen(string) - (i + 1)));
			free(*tail);
			*tail = NULL;
			*tail = fortail;
			return (1);
		}
		i++;
	}
	return (0);
}

int		search_n(char **line, char **tail, char *buf)
{
	int		i;
	char	*string;
	char	*forline;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			string = ft_strsub(buf, 0, i);
			*tail = ft_strsub(buf, i + 1, (ft_strlen(buf) - (i + 1)));
			forline = *line;
			*line = ft_strjoin(forline, string);
			free(forline);
			forline = NULL;
			free(string);
			string = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

int		read_buffer(char **line, char **tail, int fd)
{
	int		byte;
	char	*forline;
	char	buf[BUFF_SIZE + 1];

	while ((byte = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte] = '\0';
		if (search_n(line, tail, buf))
			return (1);
		forline = *line;
		*line = ft_strjoin(forline, buf);
		free(forline);
		forline = NULL;
	}
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tail[FD_MAX];

	if (fd < 0 || fd > FD_MAX || line == NULL || BUFF_SIZE <= 0 || \
			read(fd, tail[fd], 0) == -1)
		return (-1);
	if (tail[fd] == NULL)
		tail[fd] = ft_strnew(0);
	else if (line_in_tail(&tail[fd], line))
		return (1);
	*line = ft_strdup(tail[fd]);
	free(tail[fd]);
	tail[fd] = NULL;
	return (read_buffer(line, &tail[fd], fd));
}
