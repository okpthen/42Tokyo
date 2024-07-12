/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:36:22 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 17:39:33 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_redirect
{
	char	**file;
	int		*type;
}	t_redirect;

typedef struct s_cmd	t_cmd;

typedef struct s_cmd
{
	int			pipe;
	int			argc;
	char		**argv;
	char		*path;
	char		*heredoc;
	t_cmd		*next;
	t_redirect	*redi;
}	t_cmd;

typedef enum e_node_type
{
	E_NODE_PIPE = (1 << 0),
	E_NODE_SEQ = (1 << 1),
	E_NODE_REDIRECT_IN = (1 << 2),
	E_NODE_REDIRECT_IN_HEREDOC = (1 << 3),
	E_NODE_REDIRECT_OUT = (1 << 4),
	E_NODE_REDIRECT_OUT_APPEND = (1 << 5),
	E_NOOD_NEWLINE = (1 << 6),
}	t_node_type;

typedef enum e_error_num
{
	E_ERROR_PIPE = 11,
	E_ERROR_SEQ = 12,
	E_ERROR_REDIRECT_IN = 13,
	E_ERROR_REDIRECT_HEREDOC = 14,
	E_ERROR_REDIRECT_OUT = 17,
	E_ERROR_REDIRECT_APPEND = 18,
	E_ERROR_NEWLINE = 19,
	E_ERROR_OTHER = 20,
}	t_error_num;

#endif