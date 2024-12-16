/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:54:23 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/06 22:12:24 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec.h"

int	*count(int *re, t_tlist *tokens)
{
	t_tlist	*test;

	test = tokens;
	re[0] = 0;
	re[1] = 0;
	while (test && test->content->type != PIPE)
	{
		if (test->content->type == REDIR_HEREDOC
			|| test->content->type == REDIR_IN)
			re[0]++;
		if (test->content->type == REDIR_OUT
			|| test->content->type == REDIR_OUT_APPEND)
			re[1]++;
		test = test->next;
	}
	return (re);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	char	*res;

	len1 = ft_strlen(s1);
	res = (char *)malloc(len1 + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, -1);
	ft_strlcpy(res + len1, s2, -1);
	free(s1);
	return (res);
}

void	clean_close(int *fds, int pipes, int i)
{
	close_test(fds[i * 2]);
	if (i != pipes)
		close_test(fds[i * 2 + 3]);
}

void	error_message(char *name, char *error)
{
	char	*temp;

	temp = NULL;
	if (name)
	{
		temp = ft_strjoin((const char *)name, (const char *)error);
		if (!temp)
			ft_putstr_fd("An allocation failed\n", 2);
		else
			ft_putstr_fd(temp, 2);
		free(temp);
	}
	else
		ft_putstr_fd(error, 2);
}

void	end_print(char **args, char **paths)
{
	if (ft_strchr((const char *)*args, '/') != NULL || !paths)
		error_message(*args, ": No such file or directory\n");
	else
		error_message(*args, ": command not found\n");
	free_args(paths);
}
