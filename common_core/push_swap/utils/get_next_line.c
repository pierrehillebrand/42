/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:23:38 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/28 16:15:03 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../push_swap.h"

char	*ft_exit(char *result)
{
	if (result)
		free(result);
	result = NULL;
	return (NULL);
}

static char	*process_next(char *result, int fd, size_t j, int test)
{
	int		x;

	if (ft_strrchr(result, '\n') >= 0)
		return (result);
	if (!test)
		result = ft_dup2(result, j);
	if (!result)
		return (NULL);
	x = read(fd, result + j, BUFFER_SIZE);
	j += x;
	if (x < 0)
		return (ft_exit(result));
	while (ft_strrchr(result, '\n') < 0 && x == BUFFER_SIZE)
	{
		result = ft_dup2(result, j);
		if (!result)
			return (NULL);
		x = read(fd, result + j, BUFFER_SIZE);
		j += x;
	}
	return (result);
}

static char	*cut_start(char *result)
{
	size_t	j;
	size_t	i;
	char	*dest;

	i = 0;
	j = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i] || !result[i + 1])
		return (ft_exit(result));
	i++;
	while (result[j])
		j++;
	dest = ft_calloc(sizeof(char) * (j - i + 1), 1);
	if (!dest)
		return (ft_exit(result));
	j = 0;
	while (result[i + j])
	{
		dest[j] = result[i + j];
		j++;
	}
	dest[j] = 0;
	free(result);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*dest;
	size_t		j;
	int			test;

	test = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (result = ft_exit(result), NULL);
	j = ft_strlen(result);
	if (!result)
	{
		result = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1), 1);
		test = 1;
	}
	result = process_next(result, fd, j, test);
	if (!result)
		return (NULL);
	dest = dupfinal(result);
	if (!result || !dest)
		return (result = ft_exit(result), NULL);
	result = cut_start(result);
	return (dest);
}
/*
void	destruct(void)
{
	get_next_line(-4);
}
*/
/*
#include <fcntl.h>

int	main(void)
{
	int	fd = 0;
	char	*test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
}
*/
