/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:49 by phillebr          #+#    #+#             */
/*   Updated: 2024/10/02 17:53:28 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_child(int to_test, int *files, int test, char **av)
{
	int	ac;

	ac = 0;
	if (to_test >= 0)
		return ;
	while (av[ac])
		ac++;
	close_fd(files, ac, NULL);
	if (test)
	{
		if (test == 1)
			perror("Something failed ");
		exit(-1);
	}
}

static void	test_absolute(char *path[], char *av[], char *args[], int *files)
{
	if (!access(args[0], F_OK))
	{
		clean_path(path, NULL, 0);
		check_child(-1, files, 0, av);
		if (execve(args[0], args, NULL) < 0)
		{
			perror("The execution failed ");
			clean_path(args, NULL, 0);
			check_child(-1, files, 1, av);
		}
	}
}

static void	child_loop(char *path[], char *av[], char *args[], int *files)
{
	char	*cmd;
	int		j;

	j = -1;
	test_absolute(path, av, args, files);
	while (path[++j])
	{
		cmd = ft_strjoin(path[j], args[0], '/');
		if (!access(cmd, F_OK))
		{
			clean_path(path, NULL, 0);
			check_child(-1, files, 0, av);
			if (execve(cmd, args, NULL) < 0)
			{
				clean_path(args, NULL, 0);
				free(cmd);
				check_child(-1, files, 1, av);
			}
		}
		free(cmd);
	}
}

void	child(char *path[], char *av[], int *files, int i)
{
	char	**args;

	if (!path[0])
		check_child(-1, files, -1, av);
	if (files[2 * (i - 1)] < 0)
		check_child(-1, files, -1, av);
	check_child(dup2(files[2 * (i - 1)], 0), files, 1, av);
	if (!av[i + 3])
		check_child(dup2(files[2 * i + 2], 1), files, 1, av);
	else
		check_child(dup2(files[2 * i + 1], 1), files, 1, av);
	args = ft_split(av[i + 1], ' ');
	if (!args)
		check_child(-1, files, 1, av);
	child_loop(path, av, args, files);
	perror(args[0]);
	return (clean_path(args, NULL, 0), check_child(-1, files, -1, av));
}
