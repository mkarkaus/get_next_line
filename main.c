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
	int		fd;
	char	*line;

	fd = open("text1", O_RDONLY);
//	fd2 = open("text2", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
//	get_next_line(fd2, &line);
//	printf("%s", line);
	return (0);
}
