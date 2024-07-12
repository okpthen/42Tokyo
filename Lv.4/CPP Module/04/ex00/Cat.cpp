#include "Cat.hpp"

Cat::Cat() :Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Nyaaaaaaaaaaaaaan" << std::endl;
}
