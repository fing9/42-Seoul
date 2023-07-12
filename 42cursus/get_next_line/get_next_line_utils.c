/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:20:42 by seongmik          #+#    #+#             */
/*   Updated: 2023/07/12 19:49:27 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_error(char **backup, char **buf, char **line, int ft_errno)
{
	if (ft_errno == 1)
	{
		if (*backup != 0)
			free(*backup);
		*backup = 0;
		if (*line != 0)
			free(*line);
	}
	else if (ft_errno == 2)
	{
		if (*backup != 0)
			free(*backup);
		*backup = 0;
	}
	if (buf != 0)
		free(*buf);
	*buf = 0;
	return (NULL);
}

int	ft_strcpy(char *backup, char *buf, int st, int ed)
{
	int	i;

	if (backup == NULL || buf == NULL)
		return (-1);
	i = 0;
	if (st == -1 && ed == -1)
	{
		while (backup[i] != '\0')
		{
			buf[i] = backup[i];
			i++;
		}
		buf[i] = '\0';
		backup[0] = '\0';
		return (i + 1);
	}
	while (st <= ed)
	{
		backup[i++] = buf[st++];
	}
	backup[i] = '\0';
	return (i + 1);
}

char	*ft_strcat(char **backup, char **line, char **buf, int idx)
{
	char	*new_line;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	while ((*line)[i] != '\0')
		i++;
	new_line = NULL;
	new_line = (char *) malloc(sizeof(char) * (i + idx + 1));
	if (new_line == NULL)
		return (ft_error(backup, buf, line, 1));
	size = i + idx;
	ft_strcpy(new_line, *line, 0, i - 1);
	while (j < idx)
		new_line[i++] = (*buf)[j++];
	new_line[i] = '\0';
	if (*line != 0)
		free(*line);
	*line = 0;
	return (new_line);
}
