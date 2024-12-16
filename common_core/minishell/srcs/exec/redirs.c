/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:00:00 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/09 13:43:54 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*loop(char *test, char **temp, int *i, int fd)
{
	*temp = ft_strjoin_free(*temp, test);
	*temp = ft_strjoin_free(*temp, "\n");
	ft_putstr_fd(test, fd);
	ft_putstr_fd("\n", fd);
	free(test);
	test = readline("> ");
	*i += 1;
	return (test);
}

static void	heredoc(int fd, char *limiter, int type)
{
	char	*test;
	char	*temp;
	int		i;

	signal(SIGINT, SIG_IGN);
	test = readline("> ");
	i = 0;
	temp = malloc(sizeof(char));
	*temp = '\0';
	while (test && ft_strcmp(test, limiter))
		test = loop(test, &temp, &i, fd);
	if (!test)
	{
		ft_putstr_fd("warning: here-document at line ", 2);
		ft_putnbr_fd(i, 2);
		error_message(" delimited by end-of-file (wanted `", limiter);
		ft_putstr_fd("')\n", 2);
	}
	if (type == 0)
		add_history(temp);
	free(temp);
	free(test);
	close_test(fd);
}

static int	open_in(char *path, int type)
{
	int			test;

	if (type == 3)
		return (-42);
	else if (type == 1)
		test = open(path, O_RDONLY);
	else
		test = open(".temp", O_CREAT | O_RDWR | O_TRUNC, 00664);
	if (test < 0)
	{
		if (type == 1)
			error_open(path);
		else
			error_open(".temp");
		return (-42);
	}
	if (type != 1)
	{
		heredoc(test, path, type);
		open_in(".temp", type + 1);
	}
	return (test);
}

int	open_out(char *path, int type)
{
	const int	tab[] = {O_APPEND, O_TRUNC};
	int			test;

	if (type == 4 || type == 5)
		return (-42);
	test = open(path, O_CREAT | O_WRONLY | tab[type % 2], 00664);
	if (test < 0)
	{
		if (type < 6)
			error_open(path);
		return (-42);
	}
	return (test);
}

void	redir_in_out(t_tlist *tokens, int *fds)
{
	static int	(*open[])(char *path, int type) = {open_in, open_out};
	int			fail;
	int			occ[2];

	count(occ, tokens);
	fail = 0;
	if (occ[0])
		close_test(fds[0]);
	if (occ[1])
		close_test(fds[1]);
	while (tokens && tokens->content->type != PIPE)
	{
		if (tokens->content->type < 4)
		{
			fds[tokens->content->type / 2] = open[tokens->content->type / 2]
				(tokens->next->content->value,
					tokens->content->type + fail * 2);
			if (--occ[tokens->content->type / 2])
				close_test(fds[tokens->content->type / 2]);
			if (fds[tokens->content->type / 2] < 0)
				fail = 1;
		}
		tokens = tokens->next;
	}
	try_failure(tokens);
}
