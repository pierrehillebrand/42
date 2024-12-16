/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:31:33 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 17:47:53 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_FUNCS_H
# define TOKEN_FUNCS_H
# include "token.h"
# include "../env/env.h"

int			is_quote(char c);
char		*clean_substr_escape(char const *s,
				unsigned int start, size_t len);

t_tnode		*and_token(t_lexer *lexer);
t_tnode		*arg_token(t_lexer *lexer);
t_tnode		*dquote_token(t_lexer *lexer);
t_tnode		*lparen_token(t_lexer *lexer);
t_tnode		*newline_token(t_lexer *lexer);
t_tnode		*or_token(t_lexer *lexer);
t_tnode		*pipe_token(t_lexer *lexer);
t_tnode		*redir_heredoc_token(t_lexer *lexer);
t_tnode		*redir_in_token(t_lexer *lexer);
t_tnode		*redir_out_append_token(t_lexer *lexer);
t_tnode		*redir_out_token(t_lexer *lexer);
t_tnode		*rparen_token(t_lexer *lexer);
t_tnode		*squote_token(t_lexer *lexer);
t_tnode		*tilde_token(t_lexer *lexer);
t_tnode		*var_token(t_lexer *lexer);
t_tnode		*whitespace_token(t_lexer *lexer);

int			and_detect(t_lexer *lexer);
int			arg_detect(t_lexer *lexer);
int			dquote_detect(t_lexer *lexer);
int			lparen_detect(t_lexer *lexer);
int			newline_detect(t_lexer *lexer);
int			or_detect(t_lexer *lexer);
int			pipe_detect(t_lexer *lexer);
int			redir_heredoc_detect(t_lexer *lexer);
int			redir_in_detect(t_lexer *lexer);
int			redir_out_append_detect(t_lexer *lexer);
int			redir_out_detect(t_lexer *lexer);
int			rparen_detect(t_lexer *lexer);
int			squote_detect(t_lexer *lexer);
int			tilde_detect(t_lexer *lexer);
int			var_detect(t_lexer *lexer);
int			whitespace_detect(t_lexer *lexer);

t_token_err	and_parsing(t_lexer *lexer);
t_token_err	arg_parsing(t_lexer *lexer);
t_token_err	dquote_parsing(t_lexer *lexer);
t_token_err	lparen_parsing(t_lexer *lexer);
t_token_err	newline_parsing(t_lexer *lexer);
t_token_err	or_parsing(t_lexer *lexer);
t_token_err	pipe_parsing(t_lexer *lexer);
t_token_err	redir_heredoc_parsing(t_lexer *lexer);
t_token_err	redir_in_parsing(t_lexer *lexer);
t_token_err	redir_out_append_parsing(t_lexer *lexer);
t_token_err	redir_out_parsing(t_lexer *lexer);
t_token_err	rparen_parsing(t_lexer *lexer);
t_token_err	squote_parsing(t_lexer *lexer);
t_token_err	tilde_parsing(t_lexer *lexer);
t_token_err	var_parsing(t_lexer *lexer);
t_token_err	whitespace_parsing(t_lexer *lexer);

#endif