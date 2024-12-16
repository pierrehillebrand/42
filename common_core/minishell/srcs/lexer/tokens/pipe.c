/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:05 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 16:22:07 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"
#include "../../parser/parser.h"

int	pipe_detect(t_lexer *lexer)
{
	if (lexer->input[lexer->i] == '|')
		return (1);
	return (0);
}

t_tnode	*pipe_token(t_lexer *lexer)
{
	lexer->i++;
	return (new_token_node(PIPE, ft_strdup("|")));
}

static int	is_valid_next_token(t_token_id type)
{
	if (type == ARG || type == REDIR_OUT_APPEND || type == REDIR_OUT
		|| type == REDIR_HEREDOC || type == REDIR_IN)
		return (SUCCESS);
	return (FAILURE);
}

static int	check_parsing(t_token *prev_token,
	t_token *token, t_token *next)
{
	if ((!prev_token || !next) && token->type == PIPE)
		return (FAILURE);
	if (((prev_token && prev_token->type != ARG)
			|| (next && is_valid_next_token(next->type) == FAILURE))
		&& token->type == PIPE)
		return (FAILURE);
	return (SUCCESS);
}

t_token_err	pipe_parsing(t_lexer *lexer)
{
	t_token_err	err;
	t_token		*prev_token;
	t_token		*next_token;
	t_token		*token;
	t_list		*tokens;

	err = token_err_init();
	prev_token = NULL;
	tokens = lexer->tokens;
	while (err.token_idx < lexer->token_len)
	{
		token = (t_token *)tokens->content;
		if (tokens->next == NULL)
			next_token = NULL;
		else
			next_token = (t_token *)tokens->next->content;
		if (check_parsing(prev_token, token, next_token) == FAILURE)
			return (set_str_error(PIPE, token->value, err));
		prev_token = token;
		tokens = tokens->next;
		err.token_idx++;
	}
	return (err);
}
