/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:47:06 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/09 16:57:23 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../lexer/lexer.h"
# include "../env/env.h"
# include "../parser/parser.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_minishell
{
	t_lexer	*lexer;
	t_env	*env;
}	t_minishell;

extern int	g_last_signal;

t_minishell	*init_minishell(char **envp);
void		minishell_free(t_minishell *minishell);
t_lexer		*new_prompt(t_minishell *minishell);
int			lexer_next_line(t_minishell *minishell);
void		signal_init(void);
void		catch_signal(int enable);

#endif