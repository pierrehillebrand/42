/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarhi <lfarhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:51:12 by lfarhi            #+#    #+#             */
/*   Updated: 2024/09/24 17:20:07 by lfarhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SP_LIBFT_H
# define SP_LIBFT_H
# include "../../libft.h"

int	sp_putnbr(long long int nb);
int	sp_putnbr_n(long long int nb, int n);
int	sp_putstr(char *s);
int	sp_sizeof_nb_base(unsigned long long int nb,
		unsigned int base_len);
int	sp_putnbr_base(unsigned long long int nb,
		char *base, unsigned int base_len);
int	sp_maxi(int a, int b);

#endif