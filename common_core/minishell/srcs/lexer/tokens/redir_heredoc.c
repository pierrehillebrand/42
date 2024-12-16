/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:02 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 16:18:02 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"
#include "../../parser/parser.h"

int	redir_heredoc_detect(t_lexer *lexer)
{
	if (lexer->input[lexer->i] == '<'
		&& lexer->input[lexer->i + 1] == '<')
		return (1);
	return (0);
}

t_tnode	*redir_heredoc_token(t_lexer *lexer)
{
	lexer->i += 2;
	return (new_token_node(REDIR_HEREDOC, ft_strdup("<<")));
}

t_token_err	redir_heredoc_parsing(t_lexer *lexer)
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
		if (tokens->next == NULL)
			next_token = NULL;
		else
			next_token = (t_token *)tokens->next->content;
		if (token->type == REDIR_HEREDOC)
		{
			if (!next_token)
				return (set_str_error(REDIR_HEREDOC, token->value, err));
			else if (next_token->type != ARG)
				return (set_str_error(REDIR_HEREDOC, next_token->value, err));
		}
		tokens = tokens->next;
		err.token_idx++;
	}
	return (err);
}
