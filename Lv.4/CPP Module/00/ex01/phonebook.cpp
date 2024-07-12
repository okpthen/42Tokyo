/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:47:02 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/19 16:34:51 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(){}

void	PhoneBook::hello(void)
{
	std::cout << "Hollo This is My Phonebook" << std::endl;
	std::cout << "Enter comand" << std::endl;
}

void	PhoneBook::enter(void)
{
	std::cout << "Please enter comand" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "ADD    : save a new contact" << std::endl;
	std::cout << "SEARCH : display a specific contact" << std::endl;
	std::cout << "EXIT   : exit this book" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
}

void	PhoneBook::add(void)
{
	static int	i = 0;
	
	phonebook[i % 8].register_contact();
	i ++;
}

void	PhoneBook::error(void)
{
	std::cout << "Comand is <ADD> <SEARCH> <EXIT>" << std::endl;
}

void	PhoneBook::search(void)
{
	int	index;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|       ID | Firstname|  Lasename|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i ++)
		phonebook[i].show_contact(i);
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Enter index No" << std::endl;
	std::cin >> index;
	if (std::cin.eof())
	{
       std::cout << "EOF detected. Exiting program." << std::endl;
		exit(0) ;
	}
	if (std::cin.fail())
		std::cout << "Error input correct No" << std::endl;
	else if (0 <= index && index <= 7)
		phonebook[index].show_all();
	else
		std::cout << "Error input correct No" << std::endl <<std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}