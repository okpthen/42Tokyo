/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:21:32 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/04 11:14:50 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"
#include "../ft_printf/ft_printf.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("success\n");
	}
	exit(0);
}

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

void	send_char(int pid, unsigned char c)
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

void	send_message(int pid, unsigned char *str, size_t size)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	while (i < size)
	{
		c = str[i];
		send_char(pid, c);
		usleep(50);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int					p_id;
	size_t				size;
	struct sigaction	sa;

	if (-1 == sigemptyset(&sa.sa_mask))
		putstr_error("fail sigemptyset\n");
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	if (-1 == sigaction(SIGUSR1, &sa, NULL))
		putstr_error("fail sigaction\n");
	if (argc == 3)
	{
		p_id = ato_pid(argv[1]);
		size = ft_strlen1((unsigned char *)argv[2]);
		send_message(p_id, (unsigned char *)argv[2], size);
		send_char(p_id, 0);
	}
	else
	{
		ft_printf("input ./client_bonus <pid> <message>\n");
		return (0);
	}
	pause();
}
