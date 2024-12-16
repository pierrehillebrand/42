/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:15:54 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 17:02:22 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token_err	check_syntax_token(t_lexer *lexer)
{
	t_token_err		err;
	t_token_err		err_temp;
	size_t			i;
	t_token_func	token_func;

	err = token_err_init();
	i = 0;
	while (i < LEN_TOKENS)
	{
		token_func = get_token_func(i);
		err_temp = token_func.parsing(lexer);
		if (err_temp.status == FAILURE)
		{
			if (err.status == SUCCESS)
				err = err_temp;
			else
			{
				if (err_temp.token_idx < err.token_idx)
					err = err_temp;
			}
		}
		i++;
	}
	return (err);
}

t_token_err	get_malloc_error(void)
{
	t_token_err	err;

	err = token_err_init();
	err.status = FAILURE;
	err.type = LEN_TOKENS;
	err.value = NULL;
	return (err);
}

t_token_err	get_char_error(char *str)
{
	t_token_err	err;

	err = token_err_init();
	err.status = FAILURE;
	err.type = LEN_TOKENS;
	err.value = str;
	err.str_len = 1;
	return (err);
}

t_token_err	set_str_error(t_token_id type, char *str, t_token_err err)
{
	err.status = FAILURE;
	err.type = type;
	err.value = str;
	err.str_len = ft_strlen(str);
	return (err);
}

t_token_err	get_allocated_error(t_token_id type, char *str)
{
	t_token_err	err;

	err = token_err_init();
	err.status = FAILURE;
	err.type = type;
	err.value = str;
	err.str_len = ft_strlen(str);
	err.error_allocated = TRUE;
	return (err);
}
