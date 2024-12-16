/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:32:38 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 17:36:21 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "token.h"
#include "../constantes.h"

t_token_func	lexer_detect_token(t_lexer *lexer)
{
	size_t			start;
	size_t			i;
	t_token_func	token_func;

	if (lexer->i < lexer->str_len)
	{
		i = 0;
		while (i < lexer->allowed_tokens_len)
		{
			start = lexer->i;
			token_func = get_token_func(lexer->allowed_tokens[i]);
			if (token_func.detect(lexer))
			{
				lexer->i = start;
				return (token_func);
			}
			lexer->i = start;
			i++;
		}
	}
	return ((t_token_func){LEN_TOKENS, NULL, NULL, NULL});
}

t_tnode	*lexer_next_token(t_lexer *lexer)
{
	t_tnode			*token;
	t_token_func	token_func;

	if (lexer->i < lexer->str_len)
	{
		token_func = lexer_detect_token(lexer);
		if (token_func.type != LEN_TOKENS)
		{
			token = token_func.tokenize(lexer);
			if (token)
				return (token);
		}
	}
	return (NULL);
}

static t_bool	lexer_tokenize_token(t_lexer *lexer,
	t_tnode *token, t_list **lst, t_list *last)
{
	if (token)
	{
		last->next = token;
		lexer->token_len += ft_lstsize(token);
	}
	else
	{
		ft_lstclear(lst, (void (*)(void *))free_token);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	lexer_tokenize(t_lexer *lexer)
{
	t_list	head;
	t_list	*last;

	if (!lexer || !lexer->input)
		return (FAILURE);
	head.next = NULL;
	last = &head;
	while (lexer->input[lexer->i])
	{
		if (lexer_tokenize_token(lexer,
				lexer_next_token(lexer), &head.next, last) == FAILURE)
			return (FAILURE);
		while (last->next)
			last = last->next;
		if (((t_token *)last->content)->type == NEWLINE)
			break ;
	}
	lexer->tokens = head.next;
	return (SUCCESS);
}
