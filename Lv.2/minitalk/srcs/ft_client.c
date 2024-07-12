/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:33:32 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/04 16:31:32 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include "../ft_printf/ft_printf.h"

int	ato_pid(char *str)
{
	int	i;

	i = 0;
	while (*str && is_digit(*str))
	{
		i = i * 10 + (*str - '0');
		if (!is_pid(i))
			return (-1);
		str ++;
	}
	if (*str && !is_digit(*str))
		return (-1);
	return (i);
}

void	send_char(int pid, char c)
{
	int	j;
	int	check_error;

	j = 0;
	while (j < 8)
	{
		if (c % 2 == 1)
			check_error = kill(pid, SIGUSR1);
		else
			check_error = kill(pid, SIGUSR2);
		c /= 2;
		j ++;
		if (check_error == -1)
			putstr_error("failed kill\n");
		usleep(50);
	}
}

void	send_message(int pid, char *str, size_t size)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	while (i < size)
	{
		c = str[i];
		send_char(pid, c);
		usleep(100);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int		p_id;
	size_t	size;

	if (argc == 3)
	{
		p_id = ato_pid(argv[1]);
		if (p_id == -1)
		{
			ft_printf("input correct pid\n");
			return (0);
		}
		size = ft_strlen1(argv[2]);
		send_message(p_id, argv[2], size);
		send_message(p_id, "", 1);
	}
	else
		ft_printf("input ./client <pid> <message>\n");
	return (0);
}
