/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:36:18 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 17:38:57 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int	builtin_echo(int ac, char **av);
int	builtin_exit(int ac, char **av);
int	builtin_pwd(int ac, char **av);
int	builtin_unset(int ac, char **av);
int	builtin_env(int ac, char **av);

#endif
