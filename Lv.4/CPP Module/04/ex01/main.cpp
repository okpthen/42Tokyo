#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		// const Animal* i = new Cat();
		// i->makeSound();
		delete j;//should not create a leak
		// delete i;
	}
	std::cout << "-----------------------------" << std::endl ;
	{
		// Cat *a = new Cat();
		// Cat b;
		// Cat c;

		// b = c;
		// c.makeSound();
		// delete a;
	}

    return 0;
}