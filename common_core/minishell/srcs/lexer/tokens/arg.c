/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:30 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 17:55:09 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../token.h"
#include "../lexer.h"

int	is_quote(char c)
{
	if (c == '"')
		return (1);
	if (c == '\'')
		return (2);
	return (0);
}

int	arg_detect(t_lexer *lexer)
{
	int		quote;

	if (lexer->input[lexer->i] == '\\' && lexer->input[lexer->i + 1] != '\0')
		return (1);
	quote = is_quote(lexer->input[lexer->i]);
	if (quote)
	{
		lexer->i++;
		while (lexer->input[lexer->i]
			&& is_quote(lexer->input[lexer->i]) != quote)
			lexer->i++;
		if (lexer->input[lexer->i] == '\0')
			return (0);
		lexer->i++;
	}
	return (1);
}

t_token_err	arg_parsing(t_lexer *lexer)
{
	(void)lexer;
	return (token_err_init());
}

static char	*malloc_substr_escape(size_t *len, size_t *lstr,
	char const *s, unsigned int start)
{
	*lstr = ft_strlen(s);
	if (start >= *lstr)
		*len = 0;
	else if (start + *len > *lstr)
		*len = *lstr - start;
	if (*len > *lstr)
		*len = *lstr;
	return ((char *)malloc(*len + 1));
}

char	*clean_substr_escape(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	lstr;
	size_t	i;

	res = malloc_substr_escape(&len, &lstr, s, start);
	if (!res)
		return (NULL);
	if (start < lstr)
	{
		i = 0;
		while (i < len)
		{
			if (s[start] == '\\' && (s[start + 1] == '\\'
					|| s[start + 1] == '"' || s[start + 1] == '$'))
			{
				start++;
				len--;
			}
			res[i++] = s[start++];
		}
	}
	res[len] = '\0';
	return (res);
}
