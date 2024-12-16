/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:23:20 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 19:19:45 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"
# include "../env/env.h"
# include "../constantes.h"

t_token_err	parser(t_lexer *lexer, t_env *env);

t_bool		clean_args(t_lexer *lexer);
t_token_err	clean_vars(t_lexer *lexer);
t_list		*clean_var(t_lexer *lexer, t_list *current, t_bool *success);
t_token_err	clean_vars_redir(t_lexer *lexer,
				t_token *last, t_list **next, t_list *current);
void		clean_whitespace(t_lexer *lexer);
t_token_err	check_syntax_token(t_lexer *lexer);
t_token_err	get_malloc_error(void);
t_token_err	get_char_error(char *str);
t_token_err	set_str_error(t_token_id type, char *str, t_token_err err);
t_token_err	get_allocated_error(t_token_id type, char *str);

#endif