/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:04:16 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 15:06:20 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static t_bool	join_args(t_lexer *lexer, t_list *current, t_list *next)
{
	t_token	*token;
	char	*last_value;

	token = (t_token *)current->content;
	last_value = token->value;
	token->value = ft_strjoin(token->value,
			((t_token *)next->content)->value);
	free(last_value);
	if (!token->value)
		return (FAILURE);
	current->next = next->next;
	current = next->next;
	ft_lstdelone(next, (void *)free_token);
	lexer->token_len--;
	return (SUCCESS);
}

t_bool	clean_args(t_lexer *lexer)
{
	t_list	*current;
	t_list	*next;
	t_bool	finished;

	finished = FALSE;
	while (!finished)
	{
		finished = TRUE;
		current = lexer->tokens;
		while (current)
		{
			next = current->next;
			if (((t_token *)current->content)->type == ARG && next
				&& ((t_token *)next->content)->type == ARG)
			{
				if (join_args(lexer, current, next) == FAILURE)
					return (FAILURE);
				finished = FALSE;
			}
			else
				current = next;
		}
	}
	return (SUCCESS);
}
