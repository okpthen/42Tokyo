#include "Dog.hpp"

Dog::Dog() :Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	try
	{
		_brain = new Brain();
	}
	catch(const std::bad_alloc& ex)
	{
		std::cerr << "Memory allocation failed: " << ex.what() << std::endl;
		_brain = NULL;
	}
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Wan Wan Wan" << std::endl;
}

Dog::Dog(const Dog &one) :Animal(one)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = one;
}

Dog& Dog::operator=(const Dog &one)
{
	std::cout << "Dog Assinment called" << std::endl;
	if (this != &one)
	{
		_type = one._type;
		_brain = new Brain(*one._brain);
	}
	return (*this);
}