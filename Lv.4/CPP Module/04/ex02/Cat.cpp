#include "Cat.hpp"

Cat::Cat() :Aanimal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
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

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Nyaaaaaaaaaaaaaan" << std::endl;
}

Cat::Cat(const Cat &one) :Aanimal(one)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = one;
}

Cat& Cat::operator=(const Cat &one)
{
	std::cout << "Cat Assinment called" << std::endl;
	if (this != &one)
	{
		_type = one._type;
		_brain = new Brain(*one._brain);
	}
	return (*this);
}
