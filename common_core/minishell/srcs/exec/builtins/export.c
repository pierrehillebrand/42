/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:32:09 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/02 16:07:37 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char	**export(char *str, char **to_use)
{
	char	**export;
	int		i;

	i = 0;
	if (to_use && is_in(str, (const char **)to_use) >= 0)
		return (to_use);
	if (to_use)
		while (to_use[i])
			i++;
	export = malloc(sizeof(char *) * (i + 2));
	i = -1;
	if (to_use)
		while (to_use[++i])
			export[i] = to_use[i];
	else
		i = 0;
	export[i] = ft_strdup(str);
	if (!export[i])
		return (free(export), NULL);
	free(to_use);
	export[i + 1] = NULL;
	return (export);
}

static char	*str_replace(char *str)
{
	char	*new;
	int		count;
	int		i;
	int		j;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (ft_strchr("$\"\\", str[i]) != NULL)
			count++;
	}
	if (!count)
		return (ft_strdup(str));
	new = ft_calloc(i + count + 1, sizeof(char));
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (ft_strchr("$\"\\", str[i]) != NULL)
			new[i + j++] = '\\';
		new[i + j] = str[i];
	}
	return (new);
}

static int	new_var(char *str, t_minishell *minishell, int i)
{
	char	*test;
	char	*value;

	str = str_replace(str);
	test = ft_substr(str, 0, i);
	if (!test)
		return (free(str), perror("allocation failed "), -1);
	value = ft_substr(str, i + 1, -1);
	if (!value)
		return (free(str), free(test), perror("allocation failed "), -1);
	unset(minishell, test, 0);
	if (get_var(minishell->env, test).value != NULL)
		return (set_var(minishell->env, test, value),
			free(test), free(value), free(str), 0);
	else
	{
		minishell->env->vars = export(str, minishell->env->vars);
		minishell->env->vars_len += 1;
		minishell->env->user = get_var(minishell->env, "USER");
		minishell->env->home = get_var(minishell->env, "HOME");
		minishell->env->path = get_var(minishell->env, "PATH");
		free(value);
	}
	free(test);
	return (free(str), 0);
}

static int	test_export(char *str, t_minishell *minishell)
{
	int		i;
	size_t	truc;

	i = 0;
	if (!str[i])
		return (ft_putstr_fd("export: `': not a valid identifier\n", 2), 1);
	if (str[0] == '-' && str[1])
		return (str[2] = 0, ft_putstr_fd("export: ", 2),
			error_message(str, ": invalid option\nexport: usage: export [-fn] \
[name[=value] ...] or export -p\n"), 2);
	while ((str[i] != '=' || i == 0) && str[i])
	{
		if ((!i && !isalpha(str[i]) && str[i] != '_')
			|| (!ft_isalnum(str[i]) && str[i] != '_'))
			return (ft_putstr_fd("export: `", 2), ft_putstr_fd(str, 2),
				ft_putstr_fd("': not a valid identifier\n", 2), 1);
		i++;
	}
	if (!str[i] && find_var_line(minishell->env, str, &truc) == NULL)
		return (minishell->env->export
			= export(str, minishell->env->export), 0);
	else if (str[i])
		return (new_var(str, minishell, i));
	return (0);
}

int	in_export(char **args, t_minishell *minishell)
{
	int	i;
	int	fail;
	int	test;
	int	temp;

	if (!args[1] || (!args[2] && !ft_strcmp(args[1], "--")))
	{
		print_sorted(minishell->env->export, minishell->env->vars);
		return (0);
	}
	test = 0;
	i = 1;
	fail = 0;
	while (args[i])
	{
		if (minishell->env->export)
			test = 1;
		temp = test_export(args[i], minishell);
		if (temp > 0)
			fail = (fail == 2 * 2) + (fail != 2) * temp;
		if ((test && !minishell->env->export) || !minishell->env->vars)
			return (-1);
		i++;
	}
	return (fail);
}
