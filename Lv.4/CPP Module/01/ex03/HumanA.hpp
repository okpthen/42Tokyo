/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:28:03 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/18 15:06:24 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_buki;
	public:
		HumanA(std::string name, Weapon &buki);
		~HumanA();
		void	attack(void);
};

#endif