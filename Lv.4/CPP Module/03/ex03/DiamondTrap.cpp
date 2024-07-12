#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("_clap_trap")
{
	_name = "";
	_Hitpoints = FragTrap::_Hitpoints;
	_Energypoints = ScavTrap::_Energypoints;
	_Attackdamage = FragTrap::_Attackdamage;
	std::cout << "DiamondTrap Defaulg Constructor for the name ???" <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_Hitpoints = FragTrap::_Hitpoints;
	_Energypoints = ScavTrap::_Energypoints;
	_Attackdamage = FragTrap::_Attackdamage;
	std::cout << "DiamondTrap Constructor for the name " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamntTrap is deat" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamond name " << _name << " and Clap name " << ClapTrap::_name << std::endl;
	// std::cout << "name " << ScavTrap::_name << " and Clap name " << FragTrap::_name << std::endl;
}