/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:27:03 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/10 13:39:55 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_signal = 0;

static void	signal_handler(int signum)
{
	g_last_signal = signum;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	signal_handler_no_redisplay(int signum)
{
	g_last_signal = signum;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

static void	signal_handler_notprint(int signum)
{
	(void)signum;
	g_last_signal = signum;
}

void	catch_signal(int enable)
{
	struct sigaction	sa;

	g_last_signal = 0;
	if (enable == 1)
		sa.sa_handler = signal_handler;
	else if (enable == 0)
		sa.sa_handler = signal_handler_no_redisplay;
	else if (enable == 2)
		sa.sa_handler = signal_handler_notprint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	if (enable == 1 || enable == 0)
		sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	signal_init(void)
{
	struct sigaction	sa;

	g_last_signal = 0;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}
