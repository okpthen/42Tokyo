#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	Name(std::string);
		void	announce(void);
		void	randomChump(std::string name);
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
Zombie*	zombieHorde( int N, std::string name );

#endif