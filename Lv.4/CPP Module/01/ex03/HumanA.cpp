/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:27:14 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/18 15:11:53 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &buki) :_name(name), _buki(buki)
{}

HumanA::~HumanA()
{}

void	HumanA::attack(void)
{
	if (this->_buki.getType()!= "")
		std::cout << this->_name << " attacks with their " << this->_buki.getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have weapon" << std::endl;
}