/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:16:00 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 15:32:32 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "lexer.h"
#include "../constantes.h"

t_token	*new_token(t_token_id type, char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	return (token);
}

void	free_token(t_token *token)
{
	if (token->value)
		free(token->value);
	free(token);
}

t_tnode	*new_token_node(t_token_id type, char *value)
{
	t_tnode	*node;
	t_token	*token;

	token = new_token(type, value);
	if (!token)
	{
		free(value);
		return (NULL);
	}
	node = ft_lstnew(token);
	if (!node)
	{
		free_token(token);
		return (NULL);
	}
	return (node);
}

t_token_func	get_token_func(t_token_id type)
{
	static t_token_func	token_func[] = {
	{REDIR_HEREDOC, &redir_heredoc_detect,
		&redir_heredoc_token, &redir_heredoc_parsing},
	{REDIR_IN, &redir_in_detect, &redir_in_token, &redir_in_parsing},
	{REDIR_OUT_APPEND, &redir_out_append_detect,
		&redir_out_append_token, &redir_out_append_parsing},
	{REDIR_OUT, &redir_out_detect, &redir_out_token, &redir_out_parsing},
	{AND, &and_detect, &and_token, &and_parsing},
	{OR, &or_detect, &or_token, &or_parsing},
	{PIPE, &pipe_detect, &pipe_token, &pipe_parsing},
	{VAR, &var_detect, &var_token, &var_parsing},
	{LPAREN, &lparen_detect, &lparen_token, &lparen_parsing},
	{RPAREN, &rparen_detect, &rparen_token, &rparen_parsing},
	{NEWLINE, &newline_detect, &newline_token, &newline_parsing},
	{WHITESPACE, &whitespace_detect, &whitespace_token, &whitespace_parsing},
	{ARG, &arg_detect, &arg_token, &arg_parsing},
	};

	return (token_func[type]);
}

t_token_err	token_err_init(void)
{
	t_token_err	token_err;

	token_err.status = SUCCESS;
	token_err.type = 0;
	token_err.value = NULL;
	token_err.str_len = 0;
	token_err.token_idx = 0;
	token_err.error_allocated = FALSE;
	return (token_err);
}
