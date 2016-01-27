/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:51:05 by avannier          #+#    #+#             */
/*   Updated: 2016/01/27 10:52:11 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, const char *argv[])
{
	int		fd;
	int		ret;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)))
	{
		printf("LINE : %s\n", str);
		printf("\n---------\n");
		printf("RET : %d\n", ret);
	}
	printf("\n---------\n");
	printf("LINE : %s\n", str);
	printf("\n---------\n");
	printf("RET : %d\n", ret);
	close(fd);
	return (0);
}
