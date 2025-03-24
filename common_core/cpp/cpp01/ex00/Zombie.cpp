/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:22:02 by phillebr          #+#    #+#             */
/*   Updated: 2025/03/17 12:37:26 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << "\x1B[31m has died ... again\033[0m\n";
}

void	Zombie::announce()
{
	std::cout << this->_name << "\x1B[32m: BraiiiiiiinnnzzzZ...\033[0m\n";
}
