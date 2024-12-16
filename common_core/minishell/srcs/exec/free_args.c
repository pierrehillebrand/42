/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:50:49 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/05 17:48:30 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_test(int fd)
{
	if (fd && fd != 1 && fd > 0)
		close(fd);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

void	error_open(char *path)
{
	ft_putstr_fd(path, 2);
	if (errno == EACCES)
		ft_putstr_fd(": Permission denied\n", 2);
	else if (errno == ENOENT)
		ft_putstr_fd(": No such file or directory\n", 2);
	else if (errno == ENAMETOOLONG)
		ft_putstr_fd(": File name too long\n", 2);
	else
		ft_putstr_fd(": The infile did not open\n", 2);
}
