/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:27:44 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/04 15:44:32 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"

int	var_detect(t_lexer *lexer)
{
	char	c;

	c = lexer->input[lexer->i + 1];
	if (lexer->input[lexer->i] == '$' && c != '\0')
	{
		if (ft_isalpha(c) || c == '_' || c == '?'
			|| ft_isdigit(c) || c == '"' || c == '\'')
			return (1);
	}
	return (0);
}

static void	var_name(t_lexer *lexer)
{
	while (ft_isalnum(lexer->input[lexer->i])
		|| lexer->input[lexer->i] == '_')
		lexer->i++;
}

t_tnode	*var_token(t_lexer *lexer)
{
	size_t	start_len[2];
	char	*value;

	if (lexer->input[lexer->i] == '$' && lexer->input[lexer->i + 1] != '\0')
	{
		lexer->i++;
		start_len[0] = lexer->i;
		start_len[1] = 0;
		if (ft_isalpha(lexer->input[lexer->i]) || lexer->input[lexer->i] == '_')
		{
			var_name(lexer);
			start_len[1] = lexer->i - start_len[0];
		}
		else if (lexer->input[lexer->i] == '?')
		{
			start_len[0] -= 1;
			lexer->i++;
			start_len[1] = 2;
		}
		else if (ft_isdigit(lexer->input[lexer->i]))
			lexer->i++;
		value = ft_substr(lexer->input, start_len[0], start_len[1]);
		return (new_token_node(VAR, value));
	}
	return (NULL);
}

t_token_err	var_parsing(t_lexer *lexer)
{
	(void)lexer;
	return (token_err_init());
}
