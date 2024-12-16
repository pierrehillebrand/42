/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:11:33 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:27:20 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sp_libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_format.h"

static t_format	find_format(char *str, t_format lst_formats[])
{
	int	i;

	i = 0;
	while (*lst_formats[i].form != '\0')
	{
		if (*lst_formats[i].form == *str)
			return (lst_formats[i]);
		i++;
	}
	return (lst_formats[i]);
}

t_format	get_format(char *str)
{
	static t_format	lst_formats[] = {
	{"c", form_char},
	{"s", form_string},
	{"p", form_pointer},
	{"d", form_int},
	{"i", form_int},
	{"u", form_unsigned},
	{"x", form_hexa_lower},
	{"X", form_hexa_upper},
	{"%", form_percent},
	{"\0", NULL}
	};

	return (find_format(str, lst_formats));
}

int	ft_repeat_char(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
