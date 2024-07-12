/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:33:36 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/03 16:09:04 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include "../ft_printf/ft_printf.h"

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	signal_handler(int signum)
{
	static char	ch = 0;
	static int	i = 1;

	if (signum == SIGUSR1)
		ch = i + ch;
	if (i == 128)
	{
		ft_putchar(ch);
		ch = 0;
		i = 1;
	}
	else
		i *= 2;
}

int	main(void)
{
	pid_t				mypid;
	struct sigaction	sa;

	if (-1 == sigemptyset(&sa.sa_mask))
		putstr_error("fail sigemptyset\n");
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	if (-1 == sigaction(SIGUSR1, &sa, NULL))
		putstr_error("fail sigaction\n");
	if (-1 == sigaction(SIGUSR2, &sa, NULL))
		putstr_error("fail sigaction\n");
	mypid = getpid();
	ft_printf("PID = %d\n", (int)mypid);
	while (1)
		pause();
	return (0);
}
