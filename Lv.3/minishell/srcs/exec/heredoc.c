/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:39:54 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 15:30:19 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	read_and_process_input(char *buf, int buf_size)
{
	int	result;

	write(1, "> ", 2);
	result = read(0, buf, buf_size - 1);
	if (result > 0)
	{
		buf[result] = 0;
	}
	return (result);
}

int	handle_input(t_cmd *data, const char *buf, int *i)
{
	char	*tmp;
	char	*search;

	search = ft_strjoin((data->redi->file)[*i], "\n");
	if (search == NULL)
		exit(1);
	if (ft_strcmp((char *)buf, search) == 0)
	{
		free(search);
		return (1);
	}
	free(search);
	tmp = ft_strjoin(data->heredoc, buf);
	free(data->heredoc);
	data->heredoc = NULL;
	if (tmp == NULL)
		exit(1);
	data->heredoc = tmp;
	return (0);
}

int	overwrite_heredoc(t_cmd *data, int *i)
{
	int		result;
	char	buf[32];

	while (1)
	{
		result = read_and_process_input(buf, sizeof (buf));
		if (result <= 0)
			break ;
		if (handle_input(data, buf, i) != 0)
			break ;
	}
	if (result == 0)
		return (0);
	if (result < 0)
		return (-1);
	else
		return (0);
}

int	get_each_heredoc(t_cmd *data)
{
	int	i;

	i = 0;
	while (data->redi != NULL && (data->redi->file)[i] != NULL)
	{
		if ((data->redi->type)[i] == E_NODE_REDIRECT_IN)
		{
			free(data->heredoc);
			data->heredoc = NULL;
		}
		if ((data->redi->type)[i] != E_NODE_REDIRECT_IN_HEREDOC)
		{
			i++;
			continue ;
		}
		free(data->heredoc);
		data->heredoc = ft_strdup("");
		if (data->heredoc == NULL)
			exit(1);
		if (overwrite_heredoc(data, &i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	get_heredoc(t_cmd *data)
{
	t_cmd	*tmp;

	tmp = data;
	while (data != NULL)
	{
		data->heredoc = NULL;
		if (get_each_heredoc(data) == -1)
		{
			while (tmp != NULL)
			{
				free(tmp->heredoc);
				tmp->heredoc = NULL;
				tmp = tmp->next;
			}
			status_code('w', 1, 1);
			return (-1);
		}
		data = data->next;
	}
	return (0);
}
