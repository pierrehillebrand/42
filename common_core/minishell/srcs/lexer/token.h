/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:01:58 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 15:32:23 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include <libft.h>
# include <stdlib.h>
# include "../constantes.h"

/*
CMD_WORD : Mots de commande (Command Words)
ARG : Arguments (Arguments)

Redirections :
    > : REDIR_OUT
    >> : REDIR_OUT_APPEND
    < : REDIR_IN
    << : REDIR_HEREDOC

PIPE : Pipe (|)

Séparateurs de commandes:
    && : AND
    || : OR

ESCAPE : Backslash (\)
VAR : Expansion de variables ($VAR)

Parenthèses pour sous-shell :
    ( : LPAREN (Left Parenthesis)
    ) : RPAREN (Right Parenthesis)

CMD_SUB : Substitution de commande ( `command` ou $(command) )
WHITESPACE : Espaces et tabulations
COMMENT : Commentaires (#)
EOF : File (EOF)
*/

typedef enum e_token_id
{
	REDIR_HEREDOC,
	REDIR_IN,
	REDIR_OUT_APPEND,
	REDIR_OUT,
	AND,
	OR,
	PIPE,
	VAR,
	LPAREN,
	RPAREN,
	NEWLINE,
	WHITESPACE,
	ARG,
	LEN_TOKENS
}	t_token_id;

typedef struct s_token
{
	t_token_id	type;
	char		*value;
}						t_token;

typedef struct s_lexer	t_lexer;

typedef t_list			t_tnode;

typedef struct s_token_err
{
	t_bool		status;
	t_token_id	type;
	char		*value;
	size_t		str_len;
	size_t		token_idx;
	t_bool		error_allocated;
}						t_token_err;

typedef struct s_token_func
{
	t_token_id	type;
	int			(*detect)(t_lexer *lexer);
	t_tnode		*(*tokenize)(t_lexer *lexer);
	t_token_err	(*parsing)(t_lexer * lexer);
}						t_token_func;

t_token			*new_token(t_token_id type, char *value);
t_tnode			*new_token_node(t_token_id type, char *value);
void			free_token(t_token *token);
t_token_func	get_token_func(t_token_id type);
t_token_err		token_err_init(void);

#endif