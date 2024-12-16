/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_hexa_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:14:48 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:30:22 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

static int	change_flags(t_flags *flags, unsigned int nb)
{
	int	len_nb;
	int	extra;

	len_nb = sp_sizeof_nb_base(nb, 16) * (flags->precision != 0 || nb != 0);
	extra = (flags->hash != -1 && nb != 0) * 2;
	if (flags->precision >= 0)
	{
		if (flags->zero != -1)
			flags->width = flags->zero;
		flags->zero = flags->precision + extra;
	}
	return (len_nb + extra);
}

int	form_hexa_lower(t_flags *flags, va_list args)
{
	unsigned int	nb;
	int				len;
	int				len_nb;

	nb = va_arg(args, unsigned int);
	len = 0;
	len_nb = change_flags(flags, nb);
	if (flags->width > 0 && flags->width > sp_maxi(len_nb, flags->zero))
		len += ft_repeat_char(' ', flags->width - sp_maxi(len_nb, flags->zero));
	if (flags->hash > 0 && nb != 0)
		len += sp_putstr("0x");
	if (flags->zero > 0 && flags->zero > len_nb)
		len += ft_repeat_char('0', flags->zero - len_nb);
	if (flags->precision != 0 || nb != 0)
		len += sp_putnbr_base(nb, "0123456789abcdef", 16);
	if (flags->minus > 0 && flags->minus > len)
		len += ft_repeat_char(' ', flags->minus - len);
	return (len);
}
