/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:23 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 15:38:33 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	add_newline_at_end(t_lexer *lexer)
{
	t_tnode	*new_node;

	new_node = new_token_node(NEWLINE, ft_strdup("newline"));
	if (!new_node)
		return (FAILURE);
	ft_lstadd_back(&lexer->tokens, new_node);
	lexer->token_len++;
	return (SUCCESS);
}

t_token_err	parser(t_lexer *lexer, t_env *env)
{
	t_token_err	err;

	err = token_err_init();
	lexer->env = env;
	err = clean_vars(lexer);
	if (err.status == FAILURE)
		return (err);
	if (clean_args(lexer) == FAILURE)
		return (get_malloc_error());
	clean_whitespace(lexer);
	if (add_newline_at_end(lexer) == FAILURE)
		return (get_malloc_error());
	return (check_syntax_token(lexer));
}
