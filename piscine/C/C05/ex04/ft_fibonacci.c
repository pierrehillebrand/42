/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:55:55 by phillebr          #+#    #+#             */
/*   Updated: 2024/02/14 11:10:37 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	n;
	int	x;
	int	i;
	int	test;

	if (index < 0)
		return (-1);
	n = 0;
	x = 1;
	i = 0;
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	while (i < index - 1)
	{
		test = x;
		x = n + x;
		n = test;
		i++;
	}
	return (x);
}
