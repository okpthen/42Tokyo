/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:45:14 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/27 15:43:14 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*creat_map(char *map, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(size);
	while (i < size / 2)
	{
		new[i] = map[i];
		i ++;
	}
	free(map);
	return (new);
}

char	*standard_input(void)
{
	char	*map;
	int		index;
	int		size;

	size = 8;
	index = 0;
	map = malloc(size);
	map[0] = '\0';
	while (1)
	{
		if (index == size -1)
		{
			size = size * 2;
			map = creat_map(map, size);
		}
		if (read(0, &map[index], 1) <= 0)
			break ;
		index ++;
	}
	map[index] = '\0';
	return (map);
}

int	file_size(char *path)
{
	int		fd;
	int		size;
	char	*buf;

	buf = malloc(1);
	buf[0] = '\0';
	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		if (read(fd, buf, 1) == 0)
			break ;
		size ++;
	}
	close(fd);
	free(buf);
	return (size);
}

char	*read_file(char *path)
{
	int		fd;
	int		count;
	char	*str;
	int		byte;

	count = 0;
	byte = file_size(path);
	str = malloc(byte + 1);
	fd = open(path, O_RDONLY);
	while (count < byte)
	{
		read(fd, &str[count], byte);
		count ++;
	}
	str[count] = '\0';
	return (str);
}
