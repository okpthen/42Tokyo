/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:52:02 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/19 16:36:18 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(){}

std::string	Contact::input(std::string str)
{
	std::string	input;
	std::cout << "input" << str << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
       std::cout << "EOF detected. Exiting program." << std::endl;
		exit(0) ;
	}
	while (input.empty())
	{
		std::cout << "Error input " << str << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
       		std::cout << "EOF detected. Exiting program." << std::endl;
			exit(0) ;
		}
	}
	return (input);
}

std::string	Contact::output(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::register_contact(void)
{
	this->firsername = this->input("firstname");
	this->lastname = this->input("lastname");
	this->nickname = this->input("nickname");
	this->phonenumber = this->input("phonenumber");
	this->darkestsecret = this->input("darkestsecret");
}

void	Contact::show_contact(int num)
{
	if (this->firsername == "")
		return ;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << num;
	std::cout << "|";
	std::cout << std::right << std::setw(10) << this->output(this->firsername);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << this->output(this->lastname);
	std::cout << "|";
	std::cout << std::right << std::setw(10) << this->output(this->nickname);
	std::cout << "|";
	std::cout << std::endl;
}

void	Contact::show_all(void)
{
	if (this->firsername.size() == 0)
	{
		std::cout << "enmty" << std::endl;
		return ;
	}
	std::cout << "firstname     :";
	std::cout << this->firsername << std::endl;
	std::cout << "lasename      :";
	std::cout << this->lastname << std::endl;
	std::cout << "nickname      :";
	std::cout << this->nickname << std::endl;
	std::cout << "phonenumber   :";
	std::cout << this->phonenumber << std::endl;
	std::cout << "darkestsecret :";
	std::cout << this->darkestsecret << std::endl << std::endl;
}
