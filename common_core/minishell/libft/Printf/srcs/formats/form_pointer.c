/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:12:08 by lfarhi            #+#    #+#             */
/*   Updated: 2024/05/27 13:43:32 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

int	form_pointer(t_flags *flags, va_list args)
{
	unsigned long long int	nb;
	int						len;
	int						len_nb;

	nb = va_arg(args, unsigned long long int);
	len = 0;
	if (nb == 0)
		len_nb = 5;
	else
		len_nb = sp_sizeof_nb_base(nb, 16) + 2;
	if (flags->width > 0 && flags->width > len_nb)
		len += ft_repeat_char(' ', flags->width - len_nb);
	if (nb == 0)
		len += sp_putstr("(nil)");
	else
	{
		len += sp_putstr("0x");
		len += sp_putnbr_base(nb, "0123456789abcdef", 16);
	}
	if (flags->minus > 0 && flags->minus > len)
		len += ft_repeat_char(' ', flags->minus - len);
	return (len);
}
