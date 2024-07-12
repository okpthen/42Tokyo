#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class	Brain
{
	private:
		std::string	_idias[100];
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain& operator=(const Brain &other);
};

#endif
