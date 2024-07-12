#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment called" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i ++)
			this->_idias[i] = other._idias[i];
	}
	return (*this);
}
