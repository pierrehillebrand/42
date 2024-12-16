/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:56:18 by phillebr          #+#    #+#             */
/*   Updated: 2024/06/11 10:37:34 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_keep
{
	int	sharp;
	int	space;
	int	plus;
	int	min_width;
	int	minus;
	int	dot;
	int	precision;
	int	offset;
	int	zero;
	int	size;
	int	test;
	int	sign;
}		t_keep;

int		ft_putxnum(int nbr, int is_maj, t_keep keep);
int		ft_putchar(char c, t_keep keep);
int		ft_putnum(long nl, t_keep keep);
int		ft_putpointer(void *ptr, t_keep keep);
int		ft_putstr(char *str, t_keep keep);
int		ft_putunum(unsigned long num, t_keep keep);
int		put_str(char *str);
int		put_char(char c);
int		in_set(char c, char *set);
int		put_number(long nl);
int		ft_atoii(const char *str, int *count);
void	init_keep(t_keep *keep);
int		ft_strlen(char *str);
int		ft_printf(const char *str, ...);
int		start(t_keep *keep, long *nl, int len_nbr, int *len_prec);

#endif
