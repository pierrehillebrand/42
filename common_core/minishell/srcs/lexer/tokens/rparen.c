/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rparen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:27:52 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 16:15:45 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"
#include "../../parser/parser.h"

int	rparen_detect(t_lexer *lexer)
{
	if (lexer->input[lexer->i] == ')')
		return (1);
	return (0);
}

t_tnode	*rparen_token(t_lexer *lexer)
{
	lexer->i++;
	return (new_token_node(RPAREN, ft_strdup(")")));
}

t_token_err	rparen_parsing(t_lexer *lexer)
{
	t_token_err	err;
	t_token		*token;
	t_list		*tokens;

	err = token_err_init();
	tokens = lexer->tokens;
	while (err.token_idx < lexer->token_len)
	{
		token = (t_token *)tokens->content;
		if (token->type == RPAREN)
			return (set_str_error(RPAREN, token->value, err));
		tokens = tokens->next;
		err.token_idx++;
	}
	return (err);
}
