/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:15:38 by phillebr          #+#    #+#             */
/*   Updated: 2024/08/29 13:19:15 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		size;
	int		*dest;
	t_list	*pile_a;
	t_list	*pile_b;

	pile_b = NULL;
	dest = entry_check(argc, argv, &size);
	if (!dest)
		return (0);
	if (!check_sorted(dest, size))
		return (free(dest), 0);
	pile_a = create(dest, size);
	start(size, &pile_a, &pile_b);
	ft_list_clean(pile_a);
	ft_list_clean(pile_b);
	free(dest);
	return (0);
}
