/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:07:20 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/06/20 02:59:51 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	N = 10;
	Zombie	*zombies;
	Zombie	*zombies5;
	Zombie	*zombies10;
	Zombie	*zombies4;

	zombies = zombieHorde(N, "ore");
	zombies5 = zombieHorde(5, "omae");
	zombies10 = zombieHorde(10, "wasi");
	zombies4 = zombieHorde(4, "shitenno");

	for (int i = 0; i < N; i ++)
		zombies[i].announce();
	delete[] zombies;
	for (int i = 0; i < 5; i ++)
		zombies5[i].announce();
	delete[] zombies5;
	for (int i = 0; i < 10; i ++)
		zombies10[i].announce();
	for (int i = 0; i < 4; i ++)
		zombies4[i].announce();
	delete[] zombies10;
	delete[] zombies4;
	return (0);
}