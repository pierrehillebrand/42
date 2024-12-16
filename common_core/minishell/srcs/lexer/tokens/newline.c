/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:43:51 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/02 19:17:43 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"

int	newline_detect(t_lexer *lexer)
{
	if (lexer->input[lexer->i] == '\n')
		return (1);
	return (0);
}

t_tnode	*newline_token(t_lexer *lexer)
{
	lexer->i++;
	return (new_token_node(NEWLINE, ft_strdup("newline")));
}

t_token_err	newline_parsing(t_lexer *lexer)
{
	(void)lexer;
	return (token_err_init());
}
