/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:14:02 by lfarhi            #+#    #+#             */
/*   Updated: 2024/12/04 16:01:44 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <libft.h>
# include <limits.h>
# include "../constantes.h"

typedef struct s_var
{
	char	**line;
	char	*value;
	size_t	key_len;
}	t_var;

typedef struct s_env
{
	size_t	vars_len;
	char	**vars;
	char	**export;
	t_var	user;
	t_var	home;
	t_var	path;
	int		last_exit;
	char	last_exit_str[4];
	int		in_child;
}	t_env;

t_env	*init_env(char **envp);
void	*env_free(t_env *env);

void	set_last_exit(t_env *env, int exit_code);

char	**find_var_line(t_env *env, char *var, size_t *st_value);
t_var	get_var(t_env *env, char *key);
t_bool	set_var(t_env *env, char *key, char *value);

//void	env_debug_print(t_env *env);//TODO : remove

#endif