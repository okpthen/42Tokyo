#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "??? has spawned" << std::endl;
	_Hitpoints = 100;
	_Energypoints = 100;
	_Attackdamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << name << " has spawned(string)" << std::endl;
	_Hitpoints = 100;
	_Energypoints = 100;
	_Attackdamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout  << "Let's get a lot of CS" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (_Hitpoints == 0 || _Energypoints == 0)
		std::cout << "nice cs!!!!!" << std::endl;
	else
		std::cout << "Hey gyes high five and kill me" << std::endl;
}
