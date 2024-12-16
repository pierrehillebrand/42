/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:04:36 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 15:06:12 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	clean_whitespace(t_lexer *lexer)
{
	t_list	head;
	t_list	*current;
	t_list	*next;
	t_token	*token;

	head.next = lexer->tokens;
	current = &head;
	while (current->next)
	{
		next = current->next;
		token = (t_token *)next->content;
		if (token->type == WHITESPACE)
		{
			current->next = next->next;
			ft_lstdelone(next, (void *)free_token);
			lexer->token_len--;
		}
		else
			current = next;
	}
	lexer->tokens = head.next;
}
