/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:30 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 18:32:05 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"

static t_bool	arg_var(t_lexer *lexer, t_tnode **res, size_t *dlm)
{
	t_tnode	*temp[2];
	char	*value;
	t_var	var;

	value = clean_substr_escape(lexer->input, dlm[0], lexer->i - dlm[0]);
	if (!value)
		return (FAILURE);
	temp[0] = new_token_node(ARG, value);
	if (!temp[0])
		return (FAILURE);
	ft_lstadd_back(res, temp[0]);
	temp[0] = var_token(lexer);
	if (!temp[0])
		return (FAILURE);
	var = get_var(lexer->env, ((t_token *)temp[0]->content)->value);
	if (var.value)
		value = ft_strdup(var.value);
	else
		value = ft_strdup("");
	temp[1] = new_token_node(ARG, value);
	if (!temp[1])
		return (FAILURE);
	ft_lstadd_back(res, temp[1]);
	ft_lstdelone(temp[0], (void *)free_token);
	return (SUCCESS);
}

static t_bool	arg_quote_loop(t_lexer *lexer,
	int quote, t_tnode **res, size_t *dlm)
{
	while (lexer->input[lexer->i] && is_quote(lexer->input[lexer->i]) != quote)
	{
		if (quote == 1)
		{
			if (lexer->input[lexer->i] == '\\'
				&& (lexer->input[lexer->i + 1] == '\\'
					|| lexer->input[lexer->i + 1] == '"'
					|| lexer->input[lexer->i + 1] == '$'))
				lexer->i += 2;
			else if (var_detect(lexer)
				&& is_quote(lexer->input[lexer->i + 1]) != quote)
			{
				if (arg_var(lexer, res, dlm) == FAILURE)
					return (FAILURE);
				dlm[0] = lexer->i;
			}
			else
				lexer->i++;
		}
		else
			lexer->i++;
	}
	return (SUCCESS);
}

static t_tnode	*arg_token_quote(t_lexer *lexer, int quote)
{
	char	*value;
	size_t	dlm[2];
	t_tnode	*res;
	t_tnode	*temp;

	res = NULL;
	dlm[0] = lexer->i;
	if (arg_quote_loop(lexer, quote, &res, dlm) == FAILURE)
		return (NULL);
	dlm[1] = lexer->i;
	if (is_quote(lexer->input[lexer->i]) != quote)
		return (NULL);
	lexer->i++;
	if (quote == 1)
		value = clean_substr_escape(lexer->input, dlm[0], dlm[1] - dlm[0]);
	else
		value = ft_substr(lexer->input, dlm[0], dlm[1] - dlm[0]);
	if (!value)
		return (NULL);
	temp = new_token_node(ARG, value);
	if (!temp)
		return (NULL);
	ft_lstadd_back(&res, temp);
	return (res);
}

static t_tnode	*arg_escape(t_lexer *lexer)
{
	lexer->i++;
	if (lexer->input[lexer->i] == '\0')
		return (NULL);
	lexer->i++;
	return (new_token_node(ARG, ft_substr(lexer->input, lexer->i - 1, 1)));
}

t_tnode	*arg_token(t_lexer *lexer)
{
	char	*value;
	size_t	st;
	int		quote;

	if (lexer->input[lexer->i] == '\\')
		return (arg_escape(lexer));
	st = lexer->i;
	quote = is_quote(lexer->input[lexer->i]);
	if (quote)
	{
		lexer->i++;
		return (arg_token_quote(lexer, quote));
	}
	else
		while (lexer->input[lexer->i]
			&& !ft_isspace(lexer->input[lexer->i])
			&& !is_quote(lexer->input[lexer->i])
			&& lexer->input[lexer->i] != '\\'
			&& lexer_detect_token(lexer).type == ARG)
			lexer->i++;
	value = ft_substr(lexer->input, st, lexer->i - st);
	if (!value)
		return (NULL);
	return (new_token_node(ARG, value));
}
