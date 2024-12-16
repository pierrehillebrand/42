/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:38:38 by phillebr          #+#    #+#             */
/*   Updated: 2024/12/16 11:58:55 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_normal(const char *str, va_list *params, t_keep keep)
{
	int	total;

	total = 0;
	if (str[1] == 'c')
		total += ft_putchar(va_arg(*params, int), keep);
	else if (str[1] == 's')
		total += ft_putstr(va_arg(*params, char *), keep);
	else if (str[1] == 'p')
		total += ft_putpointer(va_arg(*params, void *), keep);
	else if (str[1] == 'd' || str[1] == 'i')
		total += ft_putnum(va_arg(*params, int), keep);
	else if (str[1] == 'u')
		total += ft_putunum(va_arg(*params, unsigned int), keep);
	else if (str[1] == 'x')
		total += ft_putxnum(va_arg(*params, int), 0, keep);
	else if (str[1] == 'X')
		total += ft_putxnum(va_arg(*params, int), 1, keep);
	else if (str[1] == '%')
		total += put_char('%');
	else
		total = -1;
	return (total);
}

void	process_flags(t_keep *keep, const char *str, int *i)
{
	if (str[1] == '#')
		keep->sharp = 1;
	else if (str[1] == ' ')
		keep->space = 1;
	else if (str[1] == '+')
		keep->plus = 1;
	else if (str[1] == '0')
	{
		keep->size = ft_atoii(str + 2, i);
		keep->zero = 1;
	}
	else if (str[1] == '-')
	{
		keep->offset = ft_atoii(str + 2, i);
		keep->minus = 1;
	}
	else if (str[1] == '.')
	{
		keep->precision = ft_atoii(str + 2, i);
		keep->dot = 1;
	}
}

int	process(const char *str, va_list *params, int *i)
{
	int		total;
	int		x;
	t_keep	keep;

	total = 0;
	init_keep(&keep);
	while (in_set(str[(*i) + 1], "0123456789# +-."))
	{
		if (in_set(str[(*i) + 1], "# +0-."))
			process_flags(&keep, str + (*i), i);
		else
		{
			keep.min_width = ft_atoii(str + (*i) + 1, i);
			(*i)--;
		}
		(*i)++;
	}
	x = process_normal(str + (*i), params, keep);
	if (x == -1)
		return (-1);
	total += x;
	(*i)++;
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		i;
	int		x;
	int		total;

	i = 0;
	if (!str)
		return (-1);
	total = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			x = process(str, &params, &i);
			if (x == -1)
				return (-1);
			total += x;
		}
		else
			total += put_char(str[i]);
		i++;
	}
	va_end(params);
	return (total);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("%#X\n", 0);
	printf("%#X\n", 0);
}
