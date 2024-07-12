#include "Aanimal.hpp"

Aanimal::Aanimal()
{
	_type = "";
	std::cout << "Animal constructor called" << std::endl;
}

Aanimal::Aanimal(std::string type): _type(type)
{
	std::cout << "Animal string constructor called" << std::endl;
}

Aanimal::Aanimal(const Aanimal &ani)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = ani;
}

Aanimal::~Aanimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Aanimal& Aanimal::operator=(const Aanimal & ani)
{
	std::cout << "Animal assignment called" << std::endl;
	if (this != &ani)
		_type = ani._type;
	return (*this);
}

void	Aanimal::makeSound() const
{
	std::cout  << "Gaoooooooooooo" << std::endl;
}

std::string	Aanimal::getType() const
{
	return (_type);
}