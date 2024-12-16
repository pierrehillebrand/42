/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:11:16 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 16:17:07 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../exec/exec.h"

t_minishell	*init_minishell(char **envp)
{
	t_minishell	*minishell;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->env = init_env(envp);
	if (!minishell->env)
	{
		free(minishell);
		return (NULL);
	}
	minishell->lexer = NULL;
	return (minishell);
}

void	minishell_free(t_minishell *minishell)
{
	if (minishell->env)
		env_free(minishell->env);
	if (minishell->lexer)
		lexer_free(minishell->lexer);
	free(minishell);
	rl_clear_history();
}

static void	lexer_error(t_minishell *minishell, t_token_err err, int *isend)
{
	minishell->env->last_exit = 256;
	if (err.value == NULL)
	{
		ft_putstr_fd("malloc error\n", 2);
		*isend = TRUE;
	}
	else if (err.error_allocated)
	{
		ft_putstr_fd(err.value, 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		write(2, err.value, err.str_len);
		ft_putstr_fd("'\n", 2);
	}
	ft_lstclear(&minishell->lexer->tokens, (void (*)(void *))free_token);
	minishell->lexer->tokens = NULL;
	minishell->lexer->token_len = 0;
}

int	lexer_next_line(t_minishell *minishell)
{
	t_token_err	err;
	int			isend;

	isend = FALSE;
	if (minishell->lexer->i >= minishell->lexer->str_len)
		return (TRUE);
	err = token_err_init();
	ft_lstclear(&minishell->lexer->tokens, (void (*)(void *))free_token);
	minishell->lexer->tokens = NULL;
	minishell->lexer->token_len = 0;
	if (lexer_tokenize(minishell->lexer) == FAILURE)
	{
		err = get_char_error(minishell->lexer->input + minishell->lexer->i);
		isend = TRUE;
	}
	else
		err = parser(minishell->lexer, minishell->env);
	if (err.status == FAILURE)
		lexer_error(minishell, err, &isend);
	if (err.error_allocated)
		free(err.value);
	return (isend);
}
