/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:54:39 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/15 17:16:38 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	int	fd;
	int	fd2;
	int	i;
	char	*line;

	i = 0;
	fd = open("some_lines.txt", O_RDONLY);
	fd2 = open("text1", O_RDONLY);
	line = "nappi";
	while (line)
	{
		if (i % 2 == 0)
		{
			get_next_line(fd, &line);
			printf("%s", line);
		}
		if (i % 2 != 0)
		{
			get_next_line(fd2, &line);
			printf("%s", line);
		}
		if (line[0] == '\0')
			break ;
		printf("%c", '\n');
		i++;
	}
	return (0);
}
