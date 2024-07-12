/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:27:17 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/18 15:21:11 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) :_name(name)
{											
	this->_buki = NULL;
}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon& buki)
{
	this->_buki = &buki;
}

void	HumanB::attack()
{
	if (this->_buki)
		std::cout << this->_name << " attacks with their " << this->_buki->getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have weapon" << std::endl;
}