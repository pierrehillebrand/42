/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_vars_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:07:47 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 19:38:22 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static t_token_err	join_redir_value(t_token_err err,
	t_list *current, char *value)
{
	char	*old;

	old = err.value;
	if (err.status == FAILURE)
	{
		err.value = ft_strjoin(((t_token *)current->content)->value, err.value);
		free(old);
		old = err.value;
		err.value = ft_strjoin("$", err.value);
		free(old);
	}
	else
	{
		if (value)
		{
			err.value = ft_strjoin(value, err.value);
			free(old);
		}
		if (!err.value || !value)
			err.value = ft_strdup("");
		((t_token *)current->content)->value[0] = '\0';
		((t_token *)current->content)->type = ARG;
	}
	return (err);
}

t_token_err	check_redir_error(t_lexer *lexer, t_list *current, t_bool valid)
{
	char		*value;
	t_token_err	err;

	value = get_var(lexer->env, ((t_token *)current->content)->value).value;
	if (current->next != NULL
		&& ((t_token *)current->next->content)->type == VAR)
		err = check_redir_error(lexer, current->next, valid && value);
	else if ((valid && value) || (current->next != NULL
			&& ((t_token *)current->next->content)->type == ARG))
		err = token_err_init();
	else
		err = get_allocated_error(VAR, ft_strdup(": ambiguous redirect"));
	return (join_redir_value(err, current, value));
}

t_token_err	clean_vars_redir(t_lexer *lexer,
	t_token *last, t_list **next, t_list *current)
{
	t_bool		success;
	t_token_err	err;

	success = SUCCESS;
	if (last && last->type < 4)
	{
		err = check_redir_error(lexer, current, TRUE);
		if (err.status == FAILURE)
			return (err);
		free(((t_token *)current->content)->value);
		((t_token *)current->content)->value = err.value;
	}
	else
		*next = clean_var(lexer, current, &success);
	if (success == FAILURE)
		return (get_malloc_error());
	return (token_err_init());
}
