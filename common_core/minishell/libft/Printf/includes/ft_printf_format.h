/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:29:06 by lfarhi            #+#    #+#             */
/*   Updated: 2024/05/27 13:44:32 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FORMAT_H
# define FT_PRINTF_FORMAT_H
# include <stdarg.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	plus;
	int	hash;
	int	space;
}			t_flags;
/*
** flags '0.# +' :
**
** minus: if '-' flag is present, -1 otherwise, ex: %-5d -> 5
**	| printf("%-5d", 42);-> '42   '		| printf("%-5d", -42);-> '-42   '

** zero: if '0' flag is present, -1 otherwise, ex: %05d -> 5
**	| printf("%05d", 42);-> '00042'		| printf("%05d", -42);-> '-0042'

** width: width of the output, -1 otherwise, ex: %5d -> 5
**	| printf("%5d", 42);-> '   42'		| printf("%5d", -42);-> '  -42'

** precision: precision of the output, -1 otherwise, ex: %.5d -> 5
**	| printf("%.5d", 42);-> '00042'		| printf("%.5d", 424242);-> '424242'

** plus: if '+' flag is present, -1 otherwise, ex: %+d -> 1
**	| printf("%+d", 42);-> '+42'		| printf("%+d", -42);-> '-42'

** hash: if '#' flag is present, -1 otherwise, ex: %#d -> 1
**	| printf("%#d", 42);-> '42'			| printf("%#x", 42);-> '0x2a'

** space: if ' ' flag is present, -1 otherwise, ex: % d -> 1
**	| printf("% d", 42);-> ' 42'		| printf("% d", -42);-> '-42'
*/

typedef struct s_format
{
	char	form[2];
	int		(*print)(t_flags *flags, va_list args);
}			t_format;

t_format	get_format(char *c);

int			form_char(t_flags *flags, va_list args);
int			form_hexa_lower(t_flags *flags, va_list args);
int			form_hexa_upper(t_flags *flags, va_list args);
int			form_int(t_flags *flags, va_list args);
int			form_percent(t_flags *flags, va_list args);
int			form_pointer(t_flags *flags, va_list args);
int			form_string(t_flags *flags, va_list args);
int			form_unsigned(t_flags *flags, va_list args);
int			ft_repeat_char(char c, int n);

#endif