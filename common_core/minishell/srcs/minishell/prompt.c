/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:33:20 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/03 16:03:56 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../exec/exec.h"

static char	*malloc_prompt(t_env *env, char	*cwd, size_t *lens_ret)
{
	char	*line;

	lens_ret[0] = 0;
	lens_ret[1] = 10;
	if (env->user.line)
	{
		env->user.value = (*env->user.line) + env->user.key_len + 1;
		lens_ret[1] += ft_strlen(env->user.value);
	}
	if (env->home.line)
	{
		env->home.value = (*env->home.line) + env->home.key_len + 1;
		lens_ret[0] = ft_strlen(env->home.value);
		lens_ret[1] += lens_ret[0];
	}
	lens_ret[1] += ft_strlen(cwd);
	lens_ret[1] += ft_strlen("\001\033[95m\002\001\033[39m:"
			"\002\001\033[96m~\002\001\033[39m$\002 ");
	line = malloc(lens_ret[1]);
	if (!line)
		return (NULL);
	line[0] = '\0';
	return (line);
}

static void	set_var_prompt(t_env *env, char *line, char *cwd, size_t lens[2])
{
	if (env->user.line)
	{
		ft_strlcpy(line, "\001\033[95m\002", lens[1]);
		ft_strlcat(line, env->user.value, lens[1]);
		ft_strlcat(line, "\001\033[39m\002", lens[1]);
		if (cwd)
			ft_strlcat(line, ":", lens[1]);
	}
	if (cwd)
	{
		ft_strlcat(line, "\001\033[96m\002", lens[1]);
		if (env->home.line && !ft_strncmp(cwd, env->home.value, lens[0]))
		{
			ft_strlcat(line, "~", lens[1]);
			ft_strlcat(line, cwd + lens[0], lens[1]);
		}
		else
			ft_strlcat(line, cwd, lens[1]);
		ft_strlcat(line, "\001\033[39m\002", lens[1]);
	}
}

static char	*print_prompt(t_minishell *minishell)
{
	char	*line;
	size_t	lens[2];
	t_env	*env;
	char	*cwd;

	env = minishell->env;
	env->user = get_var(env, "USER");
	env->home = get_var(env, "HOME");
	cwd = getcwd(NULL, 0);
	line = malloc_prompt(env, cwd, lens);
	if (!line)
	{
		if (cwd)
			free(cwd);
		return (NULL);
	}
	set_var_prompt(env, line, cwd, lens);
	ft_strlcat(line, "$ ", lens[1]);
	if (cwd)
		free(cwd);
	return (line);
}

t_lexer	*new_prompt(t_minishell *minishell)
{
	t_lexer	*lexer;
	char	*prompt;
	char	*str;

	prompt = print_prompt(minishell);
	if (!prompt)
		return (NULL);
	rl_on_new_line();
	rl_replace_line("", 0);
	str = readline(prompt);
	free(prompt);
	if (str)
		add_history(str);
	else
		return (NULL);
	lexer = init_lexer(str, minishell->env);
	if (!lexer)
	{
		free(str);
		ft_putstr_fd("malloc error\n", 2);
		return (NULL);
	}
	return (lexer);
}
