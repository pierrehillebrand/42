/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:26:03 by phillebr          #+#    #+#             */
/*   Updated: 2025/03/24 18:03:43 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			Harl::debug();
			std::cout << "\n[ INFO ]" << std::endl;
			Harl::info();
			std::cout << "\n[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << "\n[ ERROR ]" << std::endl;
			Harl::error();
			break;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			Harl::info();
			std::cout << "\n[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << "\n[ ERROR ]" << std::endl;
			Harl::error();
			break;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
			std::cout << "\n[ ERROR ]" << std::endl;
			Harl::error();
			break;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]";
			break;
	}
	std::cout << std::endl;
}
