#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Ohayou!!!!(Default)" << std::endl;
	_Hitpoints = 100;
	_Energypoints = 50;
	_Attackdamage = 20;
	_guard = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "Ohayou!!!!(string)" << std::endl;
	_Hitpoints = 100;
	_Energypoints = 50;
	_Attackdamage = 20;
	_guard = false;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "Ohayou!!!!(copy)" << std::endl;
	_guard = other._guard;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "Ohayou!!!!(copy assignment)" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _Hitpoints = other._Hitpoints;
        _Energypoints = other._Energypoints;
        _Attackdamage = other._Attackdamage;
        _guard = other._guard;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Oyasumi!!!!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_Energypoints != 0 && _Hitpoints != 0)
	{
		std::cout <<  _name << "'s HAKAIKOUSEN cusing " << target << " "
					<< _Attackdamage << " point of damege!" << std::endl;
		_Energypoints --;
	}
	else
		std::cout << _name << " fail to attack!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_Hitpoints == 0)
		std::cout << _name << " can't change mode" << std::endl;
	else if (_guard)
		std::cout << _name << " is already guard mode" << std::endl;
	else
	{
		std::cout << _name << " is guard mode" << std::endl;
		_guard = true;
	}
}