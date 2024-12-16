/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:27:56 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 16:19:43 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"
#include "../../parser/parser.h"

int	redir_out_append_detect(t_lexer *lexer)
{
	if (lexer->input[lexer->i] == '>'
		&& lexer->input[lexer->i + 1] == '>')
		return (1);
	return (0);
}

t_tnode	*redir_out_append_token(t_lexer *lexer)
{
	lexer->i += 2;
	return (new_token_node(REDIR_OUT_APPEND, ft_strdup(">>")));
}

t_token_err	redir_out_append_parsing(t_lexer *lexer)
{
	t_token_err	err;
	t_token		*next_token;
	t_token		*token;
	t_list		*tokens;

	err = token_err_init();
	tokens = lexer->tokens;
	while (err.token_idx < lexer->token_len)
	{
		token = (t_token *)tokens->content;
		next_token = NULL;
		if (tokens->next != NULL)
			next_token = (t_token *)tokens->next->content;
		if (token->type == REDIR_OUT_APPEND)
		{
			if (!next_token)
				return (set_str_error(REDIR_OUT_APPEND, token->value, err));
			else if (next_token->type != ARG)
				return (set_str_error(REDIR_OUT_APPEND,
						next_token->value, err));
		}
		tokens = tokens->next;
		err.token_idx++;
	}
	return (err);
}
