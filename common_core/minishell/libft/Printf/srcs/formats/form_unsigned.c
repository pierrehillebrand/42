/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:21 by lfarhi            #+#    #+#             */
/*   Updated: 2024/05/27 13:47:08 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

static int	change_flags(t_flags *flags, unsigned int nb)
{
	int	len_nb;

	len_nb = sp_sizeof_nb_base(nb, 10) * (flags->precision != 0 || nb != 0);
	if (flags->precision >= 0)
	{
		if (flags->zero != -1)
			flags->width = flags->zero;
		flags->zero = flags->precision;
	}
	return (len_nb);
}

int	form_unsigned(t_flags *flags, va_list args)
{
	unsigned int	nb;
	int				len;
	int				len_nb;

	nb = va_arg(args, unsigned int);
	len = 0;
	len_nb = change_flags(flags, nb);
	if (flags->width > 0 && flags->width > sp_maxi(len_nb, flags->zero))
		len += ft_repeat_char(' ', flags->width - sp_maxi(len_nb, flags->zero));
	if (flags->precision > 0)
		flags->zero = flags->precision;
	if (flags->precision != 0 || nb != 0)
	{
		if (flags->zero > 0 && flags->zero > len_nb)
			len += sp_putnbr_n((long long int)nb, flags->zero);
		else
			len += sp_putnbr((long long int)nb);
	}
	if (flags->minus > 0 && flags->minus > len)
		len += ft_repeat_char(' ', flags->minus - len);
	return (len);
}
