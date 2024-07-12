#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& ani);
		virtual ~Animal();
		Animal& operator=(const Animal& ani);

		virtual	void		makeSound() const;
		std::string	getType() const;
};

#endif