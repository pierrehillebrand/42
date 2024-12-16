/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:18:26 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/05 17:37:54 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char	**vars_fail(size_t *len)
{
	char	**vars;
	char	*temp;

	vars = malloc(sizeof(char *) * 3);
	if (!vars)
		return (NULL);
	vars[2] = NULL;
	*len = 2;
	temp = getcwd(NULL, 0);
	if (!temp)
		return (free(vars), NULL);
	vars[0] = ft_strjoin("PWD=", (const char *)temp);
	free(temp);
	if (!vars[0])
		return (free(vars), NULL);
	vars[1] = ft_strdup("SHLVL=1");
	if (!vars[1])
		return (free(vars[0]), free(vars), NULL);
	return (vars);
}

static char	**alloc_vars(char **envp, size_t *len)
{
	size_t	i;
	char	**vars;

	i = 0;
	while (envp[i])
		i++;
	*len = i;
	if (*len == 0)
		return (vars_fail(len));
	vars = malloc(sizeof(char *) * (i + 1));
	if (!vars)
		return (NULL);
	vars[i] = NULL;
	i = -1;
	while (envp[++i])
	{
		vars[i] = ft_strdup(envp[i]);
		if (!vars[i])
		{
			while (i--)
				free(vars[i]);
			return (free(vars), NULL);
		}
	}
	return (vars);
}

t_env	*init_env(char **envp)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	ft_memset(env, 0, sizeof(t_env));
	if (!env)
		return (env_free(env));
	env->vars = alloc_vars(envp, &env->vars_len);
	if (!env->vars)
		return (env_free(env));
	env->user = get_var(env, "USER");
	env->home = get_var(env, "HOME");
	env->path = get_var(env, "PATH");
	env->export = NULL;
	if (!get_var(env, "OLDPWD").value)
	{
		env->export = malloc(sizeof(char *) * 2);
		if (!env->export)
			return (env_free(env));
		env->export[0] = ft_strdup("OLDPWD");
		if (!env->export[0])
			return (free(env->export), env->export = NULL, env_free(env));
		env->export[1] = NULL;
	}
	env->in_child = 0;
	return (set_last_exit(env, 0), env);
}

void	*env_free(t_env *env)
{
	size_t	i;

	if (!env)
		return (NULL);
	i = 0;
	if (env->vars)
	{
		while (i < env->vars_len)
			free(env->vars[i++]);
		free(env->vars);
	}
	i = 0;
	if (env->export)
	{
		while (env->export[i])
			free(env->export[i++]);
		free(env->export);
	}
	free(env);
	return (NULL);
}

void	set_last_exit(t_env *env, int exit_code)
{
	env->last_exit = exit_code;
	ft_str_itoa(exit_code / 256, env->last_exit_str);
}
