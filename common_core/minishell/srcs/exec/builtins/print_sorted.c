/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:48:06 by phillebr          #+#    #+#             */
/*   Updated: 2024/11/19 13:49:08 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

static void	put_export(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (!str[i])
		return ;
	ft_putchar_fd(str[i++], 1);
	ft_putchar_fd('\"', 1);
	ft_putstr_fd(str + i, 1);
	ft_putchar_fd('\"', 1);
}

static void	sort_print(char **final)
{
	int		i;
	int		size;
	char	*temp;

	i = 0;
	size = 0;
	while (final[size])
		size++;
	while (++i < size)
	{
		while (i > 0 && ft_strcmp(final[i], final[i - 1]) < 0)
		{
			temp = final[i];
			final[i] = final[i - 1];
			final[i - 1] = temp;
			i--;
		}
	}
	i = -1;
	while (final[++i])
	{
		ft_putstr_fd("export ", 1);
		put_export(final[i]);
		ft_putstr_fd("\n", 1);
	}
}

void	print_sorted(char **export, char **vars)
{
	int		i;
	int		j;
	char	**final;

	if (!export)
		return (sort_print(vars));
	else
	{
		i = 0;
		while (export[i])
			i++;
		j = 0;
		while (vars[j])
			j++;
		final = ft_calloc(i + j + 1, sizeof(char *));
		i = -1;
		while (vars[++i])
			final[i] = vars[i];
		j = -1;
		while (export[++j])
			final[i + j] = export[j];
		sort_print(final);
		free(final);
	}
}
