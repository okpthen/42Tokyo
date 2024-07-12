/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:36:15 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 17:36:16 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef struct s_ast		t_ast;
typedef struct s_ast_type	t_ast_type;

# define ERRORMESSAGE "-bash: syntax error near unexpected token `%s'\n"

typedef struct s_ast
{
	int		pipe;
	int		redi;
	char	*str;
	int		error;
	t_ast	*next;
}	t_ast;

typedef enum s_status
{
	QUOTE = (1 << 0),
	DQUOTE = (1 << 1),
	ESCAPED = (1 << 2)
}	t_status;

typedef struct s_ast_type
{
	int	flag;
	int	input;
	int	output;
	int	error;
	int	pre;
}	t_ast_type;

typedef struct s_a
{
	int	i;
	int	j;
	int	t;
	int	r;
	int	status;
}	t_a;

int		input_check(char *str);
int		check_status(char c, int status);
void	print_ast(t_ast *ast);
void	expand_ast_env(t_ast *ast);
t_cmd	*make_cmd(t_ast *ast);
void	print_cmd(t_cmd *cmd);
void	clear_cmd_lst(t_cmd *cmd);
void	clear_ast(t_ast *ast);
t_ast	*split_word(char *str);
int		check_error_ast(t_ast *ast);
int		status_code(int mode, int num, int is_signal);
char	*expand_env_one(char *str);
void	cmd_arg(t_cmd *cmd, t_ast *ast);
void	cmd_redi(t_cmd *cmd, t_ast *ast);
t_cmd	*make_cmd_lst(char	*str);
int		check_error_ast(t_ast *ast);
void	print_error(int num);
void	check_error_last(t_ast *node, int r, int t);
void	type_check(char c, t_ast_type *type);
t_ast	*creat_ast_node(char *str, int r, int t);
int		check_redirection(char *str);
int		check_pipe(char *str);
char	*check_env(char *str, int i, int j);
void	skip_quote_dquote(char *str);
char	*expand_env_str(char *str);
void	expand_ast_env(t_ast *ast);

#endif