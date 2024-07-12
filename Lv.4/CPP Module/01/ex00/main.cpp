/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:10:33 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/20 02:47:30 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	{
		Zombie no1("ore");
		no1.announce();
	}
	Zombie *no2;
	no2 = newZombie("omae");
	no2->announce();
	delete no2;
	randomChump("boku");
	std::cout << "program end" << std::endl;
}
