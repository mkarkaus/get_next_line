/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:03:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/19 19:42:55 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void		ft_makeline(char **line, char **tab, const int fd)
{
	size_t	k;
	char	*temp;

	k = 0;
	temp = NULL;
	while (tab[fd][k] != '\n' && tab[fd][k] != '\0')
		k++;
	if (tab[fd][k] == '\n')
	{
		*line = ft_strsub(tab[fd], 0, k);
		temp = ft_strdup(tab[fd] + (k + 1));
		free(tab[fd]);
		tab[fd] = temp;
	}
	else
	{
		*line = ft_strdup(tab[fd]);
		free(tab[fd]);
	}
}

int			get_next_line(const int fd, char **line)
{
	ssize_t		ret;
	static char	*tab[MAX_FD];
	char		*temp;
	char		buf[BUFF_SIZE + 1];

	ret = 0;
	if (fd < 0 || fd > MAX_FD || !line || BUFF_SIZE < 1)
		return (-1);
	if (tab[fd] == NULL)
		tab[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = ft_strjoin(tab[fd], buf);
		free(tab[fd]);
		tab[fd] = temp;
		if (ft_strchr(tab[fd], '\n') != NULL)
			break ;
	}
	ft_makeline(line, tab, fd);
	if (tab[fd][0] == '\0' && ret == 0)
		return (0);
	return (1);
}
