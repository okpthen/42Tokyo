#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"

int main()
{
	{
		// const Aanimal* j = new Dog();
		// const Aanimal* i = new Cat();
		// i->makeSound();
		// Aanimal *k = new Cat();

		// delete j;//should not create a leak
		// delete i;
		// delete k;
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
	{
		// Aanimal	k;
	}
    return 0;
}