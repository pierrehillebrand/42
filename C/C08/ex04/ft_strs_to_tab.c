/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:07:29 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/21 19:51:42 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

struct s_stock_str	*ft_size_to_tab(int ac, char av**)
{
	t_stock_str	*to_return;
	int				i;

	to_return = malloc(sizeof(t_stock_str) * (ac + 1));
	to_return[ac] = 0;
}
