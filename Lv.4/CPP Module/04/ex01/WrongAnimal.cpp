#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal string constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ani)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = ani;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal & ani)
{
	std::cout << "WrongAnimal assignment called" << std::endl;
	if (this != &ani)
		_type = ani._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout  << "Wrong Gaoooooooooooo" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}