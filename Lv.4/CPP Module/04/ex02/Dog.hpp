#ifndef DOG_HPP
# define DOG_HPP

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		~Dog();

		Dog(const Dog &one);
		Dog& operator=(const Dog &one);

		void   makeSound() const;
};

#endif 