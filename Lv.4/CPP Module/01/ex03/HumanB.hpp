/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:28:05 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/18 15:20:54 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_buki;
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon& buki);
		void	attack(void);
};

#endif