/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:03:14 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/14 16:19:52 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			get_next_line(const int fd, char **line)
{
	int		ret;
	size_t	i;
	char	**tab;
	char	*buf;

	i = 0;
	tab = NULL;
	if (!(buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char))))
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		tab[fd] = ft_strjoin(tab[fd], buf);

		while (tab[fd][i] != '\n' && tab[fd][i])
		{
			write(1, &tab[fd][i], 1);
			i++;
		}
		*line = tab[fd];
	}
	return (0);
}
