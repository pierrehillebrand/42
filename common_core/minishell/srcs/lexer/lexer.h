/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:32:48 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 19:01:40 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <libft.h>
# include "token.h"
# include "../env/env.h"
# include "token_funcs.h"

typedef struct s_lexer
{
	char		*input;
	size_t		i;
	size_t		str_len;
	t_list		*tokens;
	size_t		token_len;
	t_env		*env;
	t_token_id	allowed_tokens[LEN_TOKENS];
	size_t		allowed_tokens_len;
}	t_lexer;

void			init_lexer_stack(char *input, t_lexer *lexer, t_env *env);
t_lexer			*init_lexer(char *input, t_env *env);
t_token_func	lexer_detect_token(t_lexer *lexer);
t_tnode			*lexer_next_token(t_lexer *lexer);
int				lexer_tokenize(t_lexer *lexer);
void			lexer_free(t_lexer *lexer);
void			lexer_debug_print(t_lexer *lexer);

#endif
