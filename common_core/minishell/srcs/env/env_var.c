/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:39:16 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/10 13:24:13 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	**find_var_line(t_env *env, char *var, size_t *st_value)
{
	size_t	i;
	size_t	len;

	i = 0;
	*st_value = 0;
	len = ft_strlen(var);
	while (i < env->vars_len)
	{
		if (!ft_strncmp(env->vars[i], var, len) && env->vars[i][len] == '=')
		{
			*st_value = len + 1;
			return (&(env->vars[i]));
		}
		i++;
	}
	return (NULL);
}

t_var	get_var(t_env *env, char *key)
{
	t_var	var;
	size_t	st_value;
	char	**var_line;

	ft_memset(&var, 0, sizeof(t_var));
	if (!ft_strcmp(key, "$?"))
		var.value = env->last_exit_str;
	else
	{
		var_line = find_var_line(env, key, &st_value);
		if (!var_line)
			return (var);
		var.line = var_line;
		var.value = (*var_line) + st_value;
		var.key_len = st_value - 1;
	}
	return (var);
}

static t_bool	set_var_aux(t_env *env, char *key, char *value)
{
	size_t	len;

	env->vars = ft_realloc(env->vars,
			sizeof(char *) * env->vars_len,
			sizeof(char *) * (env->vars_len + 1));
	if (!env->vars)
		return (FAILURE);
	env->vars_len++;
	len = ft_strlen(key) + ft_strlen(value) + 2;
	env->vars[env->vars_len - 1] = malloc(len);
	if (!env->vars[env->vars_len - 1])
		return (FAILURE);
	ft_strlcpy(env->vars[env->vars_len - 1], key, len);
	ft_strlcat(env->vars[env->vars_len - 1], "=", len);
	ft_strlcat(env->vars[env->vars_len - 1], value, len);
	return (SUCCESS);
}

t_bool	set_var(t_env *env, char *key, char *value)
{
	size_t	st_value;
	size_t	len;
	char	**var_line;

	var_line = find_var_line(env, key, &st_value);
	if (var_line)
	{
		len = ft_strlen(value);
		*var_line = ft_realloc(*var_line, st_value, st_value + len + 1);
		if (!*var_line)
			return (FAILURE);
		ft_strlcpy(*var_line + st_value, value, len + 1);
	}
	else if (set_var_aux(env, key, value) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
