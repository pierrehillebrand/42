/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:12:34 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:27:27 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sp_libft.h"
#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		res;

	ret = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res = ft_printf_flags((char **)&format, ap);
			if (res == -1)
				return (-1);
			ret += res;
		}
		else
			ret += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (ret);
}
