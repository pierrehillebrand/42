/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phillebr <phillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:46:30 by phillebr          #+#    #+#             */
/*   Updated: 2025/03/24 17:18:37 by phillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char *av[])
{
	std::string				nameInput;
	std::string				nameOutput;
	std::ifstream			input;
	std::ofstream			output;
	std::string				s1;
	std::string				s2;
	std::string				line;
	std::string				new_line;
	size_t					endLast;
	std::string::size_type	pos;
	
	if (ac != 4)
	{
		std::cerr << "Wrong number of args\n";
		return 1;
	}
	nameInput = av[1];
	s1 = av[2];
	s2 = av[3];
	nameOutput = nameInput + ".replace";
	input.open(nameInput, std::fstream::in);
	output.open(nameOutput, std::fstream::out);
	if (!input || !output)
	{
		std::cerr << "The oppening of the files failed\n";
		input.close();
		output.close();
	}
	while (std::getline(input, line))
	{
		new_line.clear();
		endLast = 0;
		pos = line.find(s1);
		if (pos != std::string::npos)
		{
			while (pos != std::string::npos)
			{
				new_line.append(line, endLast, pos - endLast);
				new_line.append(s2);
				endLast = pos + s1.length();
				pos = line.find(s1, endLast);
			}
			new_line.append(line, endLast, line.length());
		}
		else
			new_line = line;
		output << new_line;
		if (!input.eof())
			output << std::endl;
	}
	input.close();
	output.close();
	return (0);
}
