/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sever_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:21:35 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/03 21:01:39 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"
#include "../ft_printf/ft_printf.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	ch = 0;
	static int				i = 1;
	int						check;

	check = 0;
	(void)context;
	if (signum == SIGUSR1)
		ch = i + ch;
	if (i == 128)
	{
		write(1, &ch, 1);
		if (ch == 0)
			check = kill(info->si_pid, SIGUSR1);
		ch = 0;
		i = 1;
		if (check == -1)
			putstr_error("fail kill\n");
	}
	else
		i *= 2;
}

void	wait_signal(void)
{
	struct sigaction	act;

	act.sa_sigaction = &signal_handler;
	if (-1 == sigemptyset(&act.sa_mask))
		putstr_error("fail sigempyset\n");
	act.sa_flags = SA_SIGINFO;
	if (-1 == sigaction(SIGUSR1, &act, NULL))
		putstr_error("fail sigaction\n");
	if (-1 == sigaction(SIGUSR2, &act, NULL))
		putstr_error("fail sigaction\n");
	while (1)
		pause();
}

int	main(void)
{
	pid_t	mypid;

	mypid = getpid();
	ft_printf("PID = %d\n", (int)mypid);
	wait_signal();
	return (0);
}
