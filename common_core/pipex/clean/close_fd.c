/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:21:36 by phillebr          #+#    #+#             */
/*   Updated: 2024/10/02 14:57:45 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_fd(int *files, int ac, int *pid)
{
	int	i;

	if (files[0])
		close(files[0]);
	files[0] = 0;
	i = 2;
	if (files[(ac - 2) * 2])
		close(files[(ac - 2) * 2]);
	files[(ac - 2) * 2] = 0;
	while (i < (ac - 2) * 2 + 1)
	{
		if (files[i])
			close(files[i]);
		files[i] = 0;
		i++;
	}
	if (pid)
		free(pid);
}
