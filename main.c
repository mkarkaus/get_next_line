/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:54:39 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/29 11:27:03 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int	fd;

	// int	fd2;
	// int	i;
	// char	*temp;

	if (argc < 2)
		return (0);
	// fd2 = open(argv[1], O_RDONLY);
	// temp = " ";
	// i = 0;

	fd = open(argv[1], O_RDONLY);
	line = " ";

	// while (temp)
	// {
	// 	if (i % 2 == 0)
	// 	{
	// 		get_next_line(fd, &line);
	// 		printf("%s", line);
	// 	}
	// 	if (i % 2 != 0)
	// 	{
	// 		get_next_line(fd2, &line);
	// 		printf("%s", line);
	// 	}
	// 	temp = line;	
	// 	if (line[0] == '\0')
	// 		break ;
	// 	free(line);
	// 	printf("%c", '\n');
	// 	i++;
	// }

	while (get_next_line(fd, &line))
	{
		printf("%s", line);
		printf("%c", '\n');
		// free(line);
	}

	// printf("%d\n", get_next_line(42, &line));

//	while (1);
	return (0);
}
