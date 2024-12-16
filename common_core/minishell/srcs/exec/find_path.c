/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:15:51 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/03 16:47:03 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*ft_strjoin_sep(char *s1, char *s2, char separateur)
{
	char	*str;
	int		i;
	int		j;

	if (!*s2)
		return (ft_strdup(s2));
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2)
			+ (separateur != '\0') + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	if (separateur != '\0')
		str[i] = separateur;
	i++;
	while (s2[++j])
		str[i + j] = s2[j];
	return (str);
}

static char	**get_paths(char *envp[])
{
	int		i;
	char	**paths;

	paths = NULL;
	i = -1;
	if (!envp)
	{
		paths = ft_calloc(sizeof(char *), 1);
		return (paths);
	}
	if (!*envp)
	{
		paths = ft_calloc(sizeof(char *), 1);
		return (paths);
	}
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			paths = ft_split(envp[i] + 5, ':');
	}
	return (paths);
}

void	exe(t_minishell *minishell, char **args, int type)
{
	char	**env;
	DIR		*dir;

	dir = opendir(*args);
	if (dir)
	{
		error_message(*args, ": Is a directory\n");
		closedir(dir);
		minishell_free(minishell);
		free_args(args);
		exit (126);
	}
	if (type && !ft_strchr((const char *)*args, '/'))
		return ;
	env = minishell->env->vars;
	test_create(minishell, 1);
	minishell->env->vars = NULL;
	minishell_free(minishell);
	if (execve(*args, args, env) == -1)
	{
		perror(*args);
		free_args(env);
		free_args(args);
		exit(126);
	}
}

static void	test_paths(t_minishell *mini, char **args)
{
	char	*test;
	char	**paths;
	int		i;

	i = -1;
	paths = get_paths(mini->env->vars);
	while (paths && paths[++i])
	{
		test = ft_strjoin_sep(paths[i], *args, '/');
		if (!test)
			return (minishell_free(mini), free_args(args),
				free_args(paths), exit(FAILURE));
		if (access(test, F_OK) == 0)
		{
			free(*args);
			*args = test;
			free_args(paths);
			exe(mini, args, 0);
		}
		free(test);
	}
	return (end_print(args, paths),
		minishell_free(mini), free_args(args), exit(127));
}

void	find_path(t_minishell *minishell, char **args)
{
	const char	*builtins[] = {"cd", "echo", "env",
		"exit", "export", "pwd", "unset", NULL};
	static int	(*built[])(char **args, t_minishell *minishell) = {in_cd,
		in_echo, in_env, in_exit, in_export, in_pwd, in_unset};
	int			i;

	i = -1;
	i = is_in(*args, builtins);
	if (i != -1)
	{
		i = (*built[i])(args, minishell);
		minishell_free(minishell);
		free_args(args);
		exit(i);
	}
	test_paths(minishell, args);
}
