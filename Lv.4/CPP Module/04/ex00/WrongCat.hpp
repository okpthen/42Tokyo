#ifndef WRONGCat_HPP
# define WRONGCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	
	public:
		WrongCat();
		~WrongCat();

		void   makeSound() const;
};

#endif