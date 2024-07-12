/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:49:37 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/25 23:06:37 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"
#include <stdio.h>

char	*addchar(char *str, char *buf)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new = malloc(i + 2);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = *buf;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

char	*read_file(char *path)
{
	int		fd;
	char	*str;
	char	buf[1];

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(str);
		return (NULL);
	}
	while (read(fd, buf, 1) != 0)
	{
		str = addchar(str, buf);
		if (str == NULL)
			return (NULL);
	}
	close(fd);
	return (str);
}

//#include<stdio.h>
// int main ()
//{
//	char *str;
//	t_dict	*dict;
//	int i;
//	int	j;
//
//	i = 0;
//	str = read_file("dicts/swaped-numbers.dict");
//	j = check_dict(str);
//	dict = create_dict(str);
//	printf ("%d\n",j);
//	//if (j == 1)
//	//{
//		while (dict[i].word)
//		{
//			printf("%d %d %s\n",dict[i].key, dict[i].power, dict[i].word);
//			i ++;
//		}
//	//}
//		printf("koko %d\n\n", check_same(dict));
//	return (0);
//}
