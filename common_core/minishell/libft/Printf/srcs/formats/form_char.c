/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:25:18 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:28:10 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

int	form_char(t_flags *flags, va_list args)
{
	char	c;
	int		len;

	c = va_arg(args, int);
	len = 1;
	if (flags->width > 0)
		len += ft_repeat_char(' ', flags->width - 1);
	ft_putchar_fd(c, 1);
	if (flags->minus > 0)
		len += ft_repeat_char(' ', flags->minus - 1);
	return (len);
}
