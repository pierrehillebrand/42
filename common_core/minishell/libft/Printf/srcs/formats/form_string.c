/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:11:38 by lfarhi            #+#    #+#             */
/*   Updated: 2024/05/27 13:43:53 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

static void	change_flags(t_flags *flags, char **str, int *lenstr)
{
	int	not_null;

	not_null = *str != NULL;
	if (!not_null)
		*str = "(null)";
	*lenstr = ft_strlen(*str);
	if (flags->precision >= 0 && (flags->precision < *lenstr || !not_null))
	{
		if (not_null)
			*lenstr = flags->precision;
		else if (flags->precision < 6)
			*lenstr = 0;
	}
}

int	form_string(t_flags *flags, va_list args)
{
	char	*str;
	int		len;
	int		lenstr;

	str = va_arg(args, char *);
	len = 0;
	change_flags(flags, &str, &lenstr);
	if (flags->width > 0 && flags->width > lenstr)
		len = ft_repeat_char(' ', flags->width - lenstr);
	len += write(1, str, lenstr);
	if (flags->minus > 0 && flags->minus > len)
		len += ft_repeat_char(' ', flags->minus - len);
	return (len);
}
