/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:45 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:27:59 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sp_libft.h"
#include "../../includes/ft_printf.h"
#include "../../includes/ft_printf_format.h"

int	form_percent(t_flags *flags, va_list args)
{
	(void)flags;
	(void)args;
	ft_putchar_fd('%', 1);
	return (1);
}
