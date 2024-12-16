/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:55:11 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/10 13:50:09 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell/minishell.h"
#include "exec/exec.h"

static void	minishell_exec(t_minishell	*minishell)
{
	t_token	*first_token;

	while (lexer_next_line(minishell) == FALSE)
	{
		if (minishell->lexer->token_len != 0)
		{
			first_token = (t_token *)minishell->lexer->tokens->content;
			if (first_token->type != NEWLINE)
				exec(minishell);
			else
				set_last_exit(minishell->env, 0);
		}
		set_last_exit(minishell->env, minishell->env->last_exit);
	}
	lexer_free(minishell->lexer);
}

static void	minishell_run(t_minishell	*minishell)
{
	t_bool	run;

	run = TRUE;
	while (run)
	{
		minishell->lexer = new_prompt(minishell);
		if (g_last_signal != 0)
			set_last_exit(minishell->env, 130 * 256);
		if (minishell->lexer)
			minishell_exec(minishell);
		else
			run = FALSE;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*minishell;

	(void)argc;
	(void)argv;
	signal_init();
	minishell = init_minishell(envp);
	if (!minishell)
	{
		ft_putstr_fd("malloc error\n", 2);
		return (EXIT_FAILURE);
	}
	minishell_run(minishell);
	minishell_free(minishell);
	ft_printf("exit\n");
	return (EXIT_SUCCESS);
}
