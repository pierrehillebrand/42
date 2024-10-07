/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:13:37 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/13 19:26:28 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rec(int nb)
{
	int	x;

	x = 1;
	if (nb > 1)
		x = rec(nb - 1) * nb;
	return (x);
}

int	ft_recursive_factorial(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	x = rec(nb);
	return (x);
}
