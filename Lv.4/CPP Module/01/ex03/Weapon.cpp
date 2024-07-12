/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:27:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/01 18:32:53 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string	type)
{
	this->type = type;
}

Weapon::~Weapon()
{}

const	std::string	&Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string	type)
{
	this->type = type;
}