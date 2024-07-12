#include "Animal.hpp"

Animal::Animal()
{
	_type = "";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal string constructor called" << std::endl;
}

Animal::Animal(const Animal &ani)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = ani;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal & ani)
{
	std::cout << "Animal assignment called" << std::endl;
	if (this != &ani)
		_type = ani._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout  << "Gaoooooooooooo" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}