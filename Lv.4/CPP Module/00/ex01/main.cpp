/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:09 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/19 16:32:00 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main ()
{
	std::string command;
	PhoneBook	book;

	book.hello();
	while (1)
	{
		book.enter();
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
            std::cout << "EOF detected. Exiting program." << std::endl;
			break ;
        }
		if (std::cin.fail())
			book.error();
		else if (command == "EXIT")
			break ;
		else if (command == "ADD")
			book.add();
		else if (command == "SEARCH")
			book.search();
		else
			book.error();
	}
	return (0);
}

// int main ()
// {
// 	std::string	str1 = "aAAAAaaaaaaaaAAAAa";
// 	std::string str2 = "01231234342432432432";
// 	str1.substr(0, 9) + ".";
// 	std::cout << std::right << std::setw(10) << str2.substr(0, 9) + "." << "|" << str1 << "|" << std::endl;
// }