/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:26:12 by dtakamat          #+#    #+#             */
/*   Updated: 2024/05/24 16:26:13 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	builtin_pwd(int ac, char **av)
{
	char	buf[PATH_MAX];

	(void)ac;
	(void)av;
	if (!getcwd(buf, PATH_MAX))
		return (1);
	printf("%s\n", buf);
	return (0);
}
