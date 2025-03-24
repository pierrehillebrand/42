/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:58:20 by phillebr          #+#    #+#             */
/*   Updated: 2025/03/17 14:03:12 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*list;
	int		N = 2;
	std::string	name = "Steff";
	list = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		list[i].announce();
	delete[] list;
}
