/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:53:14 by kazokada          #+#    #+#             */
/*   Updated: 2024/02/25 16:32:09 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH2_H
# define RUSH2_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char			*read_file(char *path);
int				ft_putstr_error(char *str);
void			ft_putstr(char *str);
void			ft_putstr_flag(char *str, int flag);
char			**ft_split(char *str, char *charset);
struct s_dict	*create_dict(char *str);
int				check_dict(char *str);
struct s_numset	*convert_numset(char *nbr);
int				count_len(char *nbr);
int				put_answer(struct s_numset *numset, struct s_dict *dict,
					int numset_len);
int				check_same(struct s_dict *dict);
void			ft_freedict(struct s_dict *dict);
struct s_dict	*free_arr(char **arr, struct s_dict *dict);
int				ft_returnpower(int count, int s);
int				count_words(char *str);

typedef struct s_dict
{
	int			key;
	char		*word;
	int			power;
}				t_dict;

typedef struct s_numset
{
	int			power;
	int			num;
}				t_numset;

#endif
