/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:04:12 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 19:19:29 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static char	*malloc_var_parsing(char *text)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (text[i])
	{
		if (text[i] == '"' || text[i] == '\'')
			count++;
		i++;
		count++;
	}
	return ((char *)malloc(count + 1));
}

static char	*vars_parsing(char *text)
{
	size_t	i;
	char	*value;
	char	last;

	value = malloc_var_parsing(text);
	if (!value)
		return (NULL);
	i = 0;
	last = 0;
	while (*text)
	{
		if (last != '\\' && (*text == '"' || *text == '\''))
			value[i++] = '\\';
		value[i] = *text;
		last = *text;
		text++;
		i++;
	}
	value[i] = '\0';
	return (value);
}

static t_list	*replace_var(t_lexer *lexer,
	t_list *current, t_var var, t_bool *success)
{
	t_lexer	sub_lexer;
	char	*value;
	size_t	index;

	*success = SUCCESS;
	value = vars_parsing(var.value);
	if (!value)
		return (NULL);
	init_lexer_stack(value, &sub_lexer, lexer->env);
	sub_lexer.allowed_tokens_len = 2;
	sub_lexer.allowed_tokens[0] = WHITESPACE;
	sub_lexer.allowed_tokens[1] = ARG;
	if (lexer_tokenize(&sub_lexer) == FAILURE)
	{
		free(value);
		*success = FAILURE;
		return (NULL);
	}
	index = ft_lstindex(lexer->tokens, current);
	ft_lstremove_node(&lexer->tokens, current, (void *)free_token);
	ft_lstinsert(&lexer->tokens, index, sub_lexer.tokens);
	free(value);
	lexer->token_len += sub_lexer.token_len - 1;
	return (sub_lexer.tokens);
}

t_list	*clean_var(t_lexer *lexer,
	t_list *current, t_bool *success)
{
	t_list	*next;
	t_var	var;

	*success = SUCCESS;
	var = get_var(lexer->env, ((t_token *)current->content)->value);
	if (var.value)
	{
		next = replace_var(lexer, current, var, success);
		if (*success == FAILURE)
			return (NULL);
	}
	else
	{
		next = current->next;
		ft_lstremove_node(&lexer->tokens, current, (void *)free_token);
		lexer->token_len--;
	}
	return (next);
}

t_token_err	clean_vars(t_lexer *lexer)
{
	t_list		*current;
	t_list		*next;
	t_token		*last;
	t_token_err	err;

	current = lexer->tokens;
	last = NULL;
	while (current)
	{
		next = current->next;
		if (((t_token *)current->content)->type == VAR)
		{
			err = clean_vars_redir(lexer, last, &next, current);
			if (err.status == FAILURE)
				return (err);
		}
		else if (((t_token *)current->content)->type != WHITESPACE)
			last = current->content;
		current = next;
	}
	return (token_err_init());
}
