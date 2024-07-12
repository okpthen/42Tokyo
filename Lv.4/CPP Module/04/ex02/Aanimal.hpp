#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class Aanimal
{
	protected:
		std::string	_type;
	public:
		Aanimal();
		Aanimal(std::string type);
		Aanimal(const Aanimal& ani);
		virtual ~Aanimal();
		Aanimal& operator=(const Aanimal& ani);

		virtual	void	makeSound() const = 0;
		std::string	getType() const;
};

#endif