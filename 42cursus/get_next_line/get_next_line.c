/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:20:39 by seongmik          #+#    #+#             */
/*   Updated: 2023/07/12 19:43:17 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;
	int			idx;

	if (fd < 0)
		return (NULL);
	if (ft_loc(&backup, BUFFER_SIZE) == 0)
		return (NULL);
	buf = NULL;
	if (ft_loc(&buf, BUFFER_SIZE) == 0)
		return (ft_error(&backup, &buf, NULL, 2));
	idx = find_next(backup, 1);
	if (idx != -1)
		return (get_backup_line(&backup, &buf, idx));
	else
		idx = ft_strcpy(backup, buf, -1, -1);
	line = read_line(fd, &backup, &buf, idx);
	if (line == NULL)
		return (ft_error(&backup, &buf, NULL, 2));
	if (line[0] == '\0')
		return (ft_error(&backup, &buf, &line, 1));
	ft_error(&backup, &buf, &line, 3);
	return (line);
}

char	*read_line(int fd, char **backup, char **buf, int buf_idx)
{
	char	*line;
	int		len;
	int		idx;

	line = NULL;
	if (ft_loc(&line, buf_idx) == 0)
		return (ft_error(backup, buf, &line, 2));
	ft_strcpy(*buf, line, -1, -1);
	while (1)
	{
		len = read(fd, *buf, BUFFER_SIZE);
		if (len == -1)
			return (ft_error(backup, buf, &line, 1));
		if (len == 0)
			return (line);
		idx = find_next(*buf, 2);
		if (idx == -1)
			line = ft_strcat(backup, &line, buf, len);
		else
		{
			line = ft_strcat(backup, &line, buf, idx + 1);
			ft_strcpy(*backup, *buf, idx + 1, len - 1);
			return (line);
		}
	}
}

int	ft_loc(char **buf, int size)
{
	if (*buf == NULL)
	{
		*buf = (char *) malloc(sizeof(char) * size);
		if (*buf == NULL)
			return (0);
		(*buf)[0] = '\0';
		return (1);
	}
	return (1);
}

int	find_next(char *buf, int bufno)
{
	int	idx;

	idx = 0;
	if (bufno == 1)
	{
		while (buf[idx] != '\0')
		{
			if (buf[idx] == '\n')
				return (idx);
			idx++;
		}
	}
	else if (bufno == 2)
	{
		while (idx < BUFFER_SIZE && buf[idx] != '\0')
		{
			if (buf[idx] == '\n')
				return (idx);
			idx++;
		}
	}
	return (-1);
}

char	*get_backup_line(char **backup, char **buf, int idx)
{
	char	*line;
	int		i;

	line = NULL;
	if (ft_loc(&line, idx + 2) == 0)
		return (ft_error(backup, buf, &line, 2));
	ft_strcpy(line, *backup, 0, idx);
	i = 0;
	idx++;
	while ((*backup)[idx] != '\0')
		(*backup)[i++] = (*backup)[idx++];
	(*backup)[i] = '\0';
	ft_error(backup, buf, &line, 3);
	return (line);
}
