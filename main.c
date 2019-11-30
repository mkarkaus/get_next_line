/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:54:39 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/25 14:47:26 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		main()
{
	int	fd;
	int	fd2;
	int	i;
	char	*line;
	char	*temp;

	temp = "nuppi";
	i = 0;
	fd = open("text1", O_RDONLY);
//	dup2(fd, 500);
	fd2 = open("text4", O_RDONLY);
	line = "nuppi";

//	get_next_line(fd, &line);
//	printf("%s", line);
//	free(line);

	while (temp)
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
		temp = line;
		if (line[0] == '\0')
			break ;
		free(line);
		printf("%c", '\n');
		i++;
	}
//	get_next_line(fd, &line);
//	printf("%s", line);
//	free(line);
//	while (1)
//	{
	
//	}
	return (0);
}
