/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:14:38 by yoishi            #+#    #+#             */
/*   Updated: 2024/02/25 23:06:18 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

//#include <libc.h>
//
//__attribute__((destructor)) static void destructor()
//{
//	system("leaks -q rush-02");
//}

t_dict	*set_dict(char *path);
char	*set_nbr(int ac, char **av);
char	*set_path(int ac, char **av);
void	pfree(t_dict *dict, t_numset *numset);

int	main(int ac, char **av)
{
	t_dict		*dict;
	char		*path;
	char		*nbr;
	t_numset	*numset;

	if (ac == 1 || ac >= 4)
		return (ft_putstr_error("Error"));
	nbr = set_nbr(ac, av);
	path = set_path(ac, av);
	if (path == NULL)
		return (ft_putstr_error("Error"));
	numset = convert_numset(nbr);
	if (numset == NULL)
		return (ft_putstr_error("Error"));
	dict = set_dict(path);
	if (dict == NULL)
	{
		free(numset);
		return (0);
	}
	if (!(put_answer(numset, dict, count_len(nbr) - 1)))
		ft_putstr_error("Dict Error");
	pfree(dict, numset);
}

t_dict	*set_dict(char *path)
{
	char	*str;
	t_dict	*dict;

	str = read_file(path);
	if (str == NULL)
	{
		ft_putstr_error("Error");
		return (NULL);
	}
	if (!check_dict(str))
	{
		free(str);
		ft_putstr_error("Dict Error");
		return (NULL);
	}
	dict = create_dict(str);
	if (dict == NULL)
		ft_putstr_error("Dict Error");
	else if (!check_same(dict))
	{
		ft_putstr_error("Dict Error");
		ft_freedict(dict);
		return (NULL);
	}
	return (dict);
}

char	*set_path(int ac, char **av)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	if (ac == 2)
		path = "./dicts/numbers.dict";
	else
	{
		path = av[1];
		while (path[i])
			i++;
		if (i < 6)
			return (NULL);
		if (!(path[i - 1] == 't' && path[i - 2] == 'c' && path[i - 3] == 'i'
				&& path[i - 4] == 'd' && path[i - 5] == '.'))
			return (NULL);
	}
	return (path);
}

char	*set_nbr(int ac, char **av)
{
	char	*nbr;

	nbr = NULL;
	if (ac == 2)
		nbr = av[1];
	else
		nbr = av[2];
	return (nbr);
}

void	pfree(t_dict *dict, t_numset *numset)
{
	t_dict	*start;

	start = dict;
	if (dict != NULL)
	{
		while ((*dict).word)
		{
			if ((*dict).word)
				free(dict->word);
			dict++;
		}
		free(start);
	}
	free(numset);
}
