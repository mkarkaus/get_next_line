/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:03:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/15 17:07:59 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		ft_makeline(char **line, char **tab, int fd)
{
	size_t	k;
	char	*temp;

	k = 0;
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
		*line = ft_strsub(tab[fd], 0, k);
		free(tab[fd]);
	}
}
int			get_next_line(const int fd, char **line)
{
	size_t		ret;
	static char	*tab[4864];
	char		buf[BUFF_SIZE + 1];

	line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (tab[fd] != NULL)
			tab[fd] = ft_strjoin(tab[fd], buf);
		if (tab[fd] == NULL)
			tab[fd] = ft_strdup(buf);
		if ((ft_strchr(tab[fd], '\n') != NULL))
			break ;
	}	
	ft_makeline(line, &tab[fd], fd);
	if (ret == 0)
		return (0);
	return (1);
}
