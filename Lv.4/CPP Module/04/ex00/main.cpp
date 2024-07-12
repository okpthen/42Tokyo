#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "----------Cat test----------" << std::endl;
	{
    	Animal* animal = new Cat();
		animal->makeSound();
    	delete animal;
    	Animal animal2;
    	animal2.makeSound();

    	Cat cat;
    	cat.makeSound();
	}
	std::cout << "----------Wrong cat test----------" << std::endl;
	{
	 	WrongAnimal* animal = new WrongCat();
		animal->makeSound();
    	delete animal;
    	WrongAnimal animal2;
    	animal2.makeSound();

    	WrongCat cat;
    	cat.makeSound();
	}
	std::cout << "----------Dog test----------" << std::endl;
	{
    	Animal* animal = new Dog();
		animal->makeSound();
    	delete animal;
    	Animal animal2;
    	animal2.makeSound();

    	Dog dog;
    	dog.makeSound();
	}

    return 0;
}