/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:11 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:30:16 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

static int	sizeof_int(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	change_flags(t_flags *flags, int nb)
{
	int	len_nb;

	len_nb = sizeof_int(nb) * (flags->precision != 0 || nb != 0);
	if (flags->precision >= 0)
	{
		if (flags->zero > 0)
			flags->width = flags->zero;
		flags->zero = flags->precision + (nb < 0);
	}
	if ((flags->space > 0 || flags->plus > 0) && nb >= 0)
	{
		if (flags->width > 1)
			flags->width--;
		else if (flags->zero != -1 && flags->precision == -1)
			flags->zero--;
	}
	return (len_nb);
}

int	form_int(t_flags *flags, va_list args)
{
	int	nb;
	int	len;
	int	len_nb;

	nb = va_arg(args, int);
	len = 0;
	len_nb = change_flags(flags, nb);
	if (flags->width > 0 && flags->width > sp_maxi(len_nb, flags->zero))
		len += ft_repeat_char(' ', flags->width - sp_maxi(len_nb, flags->zero));
	if (flags->plus > 0 && nb >= 0)
		len += write(1, "+", 1);
	if (flags->space > 0 && nb >= 0)
		len += write(1, " ", 1);
	if (flags->precision != 0 || nb != 0)
	{
		if (flags->zero > 0 && flags->zero > len_nb)
			len += sp_putnbr_n(nb, flags->zero);
		else
			len += sp_putnbr(nb);
	}
	if (flags->minus > 0 && flags->minus > len)
		len += ft_repeat_char(' ', flags->minus - len);
	return (len);
}
