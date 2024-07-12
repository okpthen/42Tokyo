#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	randomChump(std::string name);
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif