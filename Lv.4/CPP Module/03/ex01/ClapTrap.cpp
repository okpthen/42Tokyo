#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
{
	std::cout << "Default constructor called" << std::endl;
	_name = "";
	_Hitpoints = 10;
	_Energypoints = 10;
	_Attackdamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "String constructor called" << std::endl;
	_name = name;
	_Hitpoints = 10;
	_Energypoints = 10;
	_Attackdamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap & other)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_Hitpoints = other._Hitpoints;
	_Energypoints = other._Energypoints;
	_Attackdamage = other._Attackdamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this !=  &other)
	{
		_name = other._name;
		_Hitpoints = other._Hitpoints;
		_Energypoints = other._Energypoints;
		_Attackdamage = other._Attackdamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout <<"Destructor called" <<std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_Energypoints != 0 && _Hitpoints != 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", cusing " 
					<< _Attackdamage << " point of damege!" << std::endl;
		_Energypoints --;
	}
	else
		std::cout << "ClapTrap " << _name << " fail to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_Hitpoints == 0)
	{
		std::cout << _name << "has already been dead!" << std::endl;
		return ;
	}
	if (_Hitpoints > amount)
	{
		std::cout << _name << " take " << amount
					<< " point of damege!" << std::endl;
		_Hitpoints -= amount;
	}
	else
	{
		std::cout << _name << " take " << amount
					<< " point of damege!" << std::endl;
		std::cout << _name << "is dead" << std::endl;
		_Hitpoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energypoints != 0 && _Hitpoints != 0)
	{
		std::cout << _name << "is repaired " << amount
					<< " point!" << std::endl;
		_Hitpoints += amount;
		_Energypoints --;
	}
	else
		std::cout << _name << " fail to repaired!" << std::endl;
}


unsigned int	ClapTrap::getAttack()
{
	return (_Attackdamage);
}

unsigned int	ClapTrap::getEnergy()
{
	return (_Energypoints);
}
unsigned int	ClapTrap::getHitpoint()
{
	return (_Hitpoints);
}
std::string		ClapTrap::getName()
{
	return (_name);
}

//ClapTrap <name> attacks <target>, causing <damage> points of damage!