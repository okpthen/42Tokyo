/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtakamat <dtakamat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:19:30 by dtakamat          #+#    #+#             */
/*   Updated: 2024/06/30 14:00:14 by dtakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	setup_terminal(int n)
{
	struct termios	term;

	rl_outstream = stderr;
	if (isatty(STDIN_FILENO) == 0)
		return ;
	if (tcgetattr(STDIN_FILENO, &term) == -1)
		exit(-1);
	if (n == 0)
		term.c_lflag &= ~ECHOCTL;
	else
		term.c_lflag |= ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		exit(-1);
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
	rl_on_new_line();
	if (sig == SIGINT)
		rl_replace_line("", 1);
	if (sig == SIGINT)
		status_code('w', 1, 0);
	rl_redisplay();
}

char	*loop(void)
{
	char				*input;
	struct sigaction	sa_sig;
	struct sigaction	sa_old;

	setup_terminal(0);
	sa_sig.sa_handler = sig_handler;
	sigemptyset(&sa_sig.sa_mask);
	sa_sig.sa_flags = 0;
	if (sigaction(SIGQUIT, &sa_sig, &sa_old) == -1
		|| sigaction(SIGINT, &sa_sig, &sa_old) == -1)
		exit (1);
	input = readline("$> ");
	while (input != NULL && input[0] == 0)
	{
		free(input);
		input = readline("$> ");
	}
	if (input)
		add_history(input);
	else
		write(2, "exit\n", 5);
	if (sigaction(SIGQUIT, &sa_old, NULL) == -1
		|| sigaction(SIGINT, &sa_old, NULL) == -1)
		exit (1);
	return (setup_terminal(1), input);
}

// int	main(void)
// {
// 	char	*re;
// 	while (1)
// 	{
// 		re = loop();
// 		if (re == NULL)
// 			return (1);
// 		printf("%s\n", re);
// 		free(re);
// 	}
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }