#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <limits> 
#include <cstdlib>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_Hitpoints;
		unsigned int	_Energypoints;
		unsigned int	_Attackdamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& othre);
		ClapTrap& operator=(const ClapTrap& othre);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		unsigned int	getAttack(void);
		unsigned int	getHitpoint(void);
		unsigned int	getEnergy(void);
		std::string		getName(void);
};

#endif