/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongmik <seongmik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:20:40 by seongmik          #+#    #+#             */
/*   Updated: 2023/07/12 19:20:07 by seongmik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_loc(char **buf, int size);
int		find_next(char *buf, int bufno);
char	*get_backup_line(char **backup, char **buf, int idx);
char	*read_line(int fd, char **backup, char **buf, int buf_idx);
char	*ft_error(char **backup, char **buf, char **line, int ft_errno);
int		ft_strcpy(char *backup, char *buf, int st, int ed);
char	*ft_strcat(char **backup, char **line, char **buf, int idx);

#endif