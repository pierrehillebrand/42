/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:27:36 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 16:25:58 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"

int	whitespace_detect(t_lexer *lexer)
{
	if (ft_isspace(lexer->input[lexer->i]))
		return (1);
	return (0);
}

t_tnode	*whitespace_token(t_lexer *lexer)
{
	size_t	start;

	start = lexer->i;
	while (ft_isspace(lexer->input[lexer->i]))
		lexer->i++;
	return (new_token_node(WHITESPACE,
			ft_substr(lexer->input, start, lexer->i - start)));
}

t_token_err	whitespace_parsing(t_lexer *lexer)
{
	(void)lexer;
	return (token_err_init());
}
