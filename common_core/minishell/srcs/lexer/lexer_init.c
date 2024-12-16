/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:32:38 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/05 14:30:06 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "token.h"
#include "../constantes.h"

void	init_lexer_stack(char *input, t_lexer *lexer, t_env *env)
{
	size_t	i;

	lexer->input = input;
	lexer->i = 0;
	lexer->str_len = ft_strlen(input);
	lexer->tokens = NULL;
	lexer->token_len = 0;
	lexer->env = env;
	i = 0;
	while (i < LEN_TOKENS)
	{
		lexer->allowed_tokens[i] = i;
		i++;
	}
	lexer->allowed_tokens_len = LEN_TOKENS;
}

t_lexer	*init_lexer(char *input, t_env *env)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	init_lexer_stack(input, lexer, env);
	return (lexer);
}

void	lexer_free(t_lexer *lexer)
{
	if (!lexer)
		return ;
	if (lexer->input)
		free(lexer->input);
	ft_lstclear(&lexer->tokens, (void (*)(void *))free_token);
	free(lexer);
}

void	lexer_debug_print(t_lexer *lexer)
{
	static char	*token_type_str[] = {
		"REDIR_HEREDOC", "REDIR_IN", "REDIR_OUT_APPEND",
		"REDIR_OUT", "AND", "OR", "PIPE", "VAR", "LPAREN",
		"RPAREN", "NEWLINE", "WHITESPACE", "ARG",
		"LEN_TOKENS"
	};
	t_list		*lst;
	t_token		*token;

	lst = lexer->tokens;
	while (lst)
	{
		token = (t_token *)lst->content;
		ft_putstr_fd(token_type_str[token->type], 1);
		ft_putstr_fd(": ", 1);
		if (token->value)
			ft_putendl_fd(token->value, 1);
		else
			ft_putendl_fd("NULL", 1);
		lst = lst->next;
	}
}
