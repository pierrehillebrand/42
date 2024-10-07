/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:41:10 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/14 10:15:29 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rec(int nb, int power)
{
	int	x;

	x = 1;
	if (power > 0)
		x = nb * rec(nb, power - 1);
	return (x);
}

int	ft_recursive_power(int nb, int power)
{
	int	x;

	x = 1;
	if (power < 0)
		return (0);
	if (power == (0))
		return (1);
	x = rec(nb, power);
	return (x);
}
