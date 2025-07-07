/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:40:42 by phillebr          #+#    #+#             */
/*   Updated: 2025/06/30 18:45:44 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_pid(void)
{
	wait(NULL);
}

static char	**get_path(char *envp[])
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
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			paths = ft_split(envp[i] + 5, ':');
	}
	if (!paths)
	{
		paths = ft_calloc(sizeof(char *), 1);
		return (paths);
	}
	return (paths);
}

static void	process(char *paths[], char *av[], int *files, int ac)
{
	int	i;
	int	fd_exit;
	int	*pid;

	i = 1;
	fd_exit = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 00644);
	if (fd_exit < 3)
		return (perror("The outfile did not open "));
	files[(ac - 2) * 2] = fd_exit;
	pid = ft_calloc(sizeof(int), ac - 1);
	if (!pid)
		return (close(fd_exit), perror("The allocation failed "));
	while (i < ac - 2 )
	{
		if (pipe(files + i * 2))
			return (close_fd(files, ac, NULL), perror("The pipe failed "));
		pid[i] = fork();
		if (pid[i] < 0)
			return (close_fd(files, ac, NULL), perror("The fork failed "));
		if (pid[i] == 0)
			child(paths, av, files, i);
		i++;
	}
	wait_pid();
	close_fd(files, ac, pid);
}

int	main(int ac, char *av[], char *envp[])
{
	char	**paths;
	int		fd;
	int		*files;
	int		x;

	x = 0;
	if (ac <= 4)
		return (ft_putstr("Wrong number of arguments\n"));
	paths = get_path(envp);
	if (!paths)
		return (perror("The path malloc failed "), -1);
	if (!paths[0])
		x = 128;
	fd = open(av[1], O_RDONLY);
	if (fd < 3)
		perror(av[1]);
	files = ft_calloc(sizeof(int), (ac - 2) * 2 + 1);
	if (!files)
		return (perror("Malloc failed "), close(fd));
	files[0] = fd;
	process(paths, av, files, ac);
	clean_path(paths, NULL, 0);
	free(files);
	exit(x);
}
