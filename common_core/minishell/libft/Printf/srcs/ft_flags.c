/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:40:29 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:27:30 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sp_libft.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_printf_format.h"

static void	flags_init(t_flags *flags)
{
	flags->minus = -1;
	flags->zero = -1;
	flags->width = -1;
	flags->precision = -1;
	flags->plus = -1;
	flags->hash = -1;
	flags->space = -1;
}

static int	get_width_flags(char **str)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + **str - '0';
		(*str)++;
	}
	return (width);
}

static int	check_flag(char **str, char want, int skip, int *out)
{
	if (**str != want)
		return (0);
	if (skip)
		*str += 1;
	if (out)
		*out = 1;
	return (1);
}

static void	detect_flags(t_flags *flags, char **str)
{
	while (ft_isdigit(**str) || **str == '.' || **str == '-'
		|| **str == '+' || **str == ' ' || **str == '#')
	{
		check_flag(str, '#', 1, &flags->hash);
		check_flag(str, '+', 1, &flags->plus);
		check_flag(str, ' ', 1, &flags->space);
		if (check_flag(str, '0', 1, NULL)
			|| (flags->zero == 0 && ft_isdigit(**str)))
			flags->zero = get_width_flags(str);
		if (check_flag(str, '-', 1, NULL)
			|| (flags->minus == 0 && ft_isdigit(**str)))
			flags->minus = get_width_flags(str);
		if (ft_isdigit(**str))
			flags->width = get_width_flags(str);
		if (check_flag(str, '.', 1, NULL))
			flags->precision = get_width_flags(str);
	}
}

int	ft_printf_flags(char **str, va_list args)
{
	t_format	format;
	t_flags		flags;

	flags_init(&flags);
	detect_flags(&flags, str);
	format = get_format(*str);
	if (*format.form == '\0')
	{
		return (write(1, "%", 1) + write(1, *str, 1));
	}
	return (format.print(&flags, args));
}
