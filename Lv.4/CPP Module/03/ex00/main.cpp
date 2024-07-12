#include "ClapTrap.hpp"

int main ()
{
	ClapTrap	type2;
	ClapTrap	type1("ore");
	ClapTrap	type3(type1);
	ClapTrap	type4("4gou");
	type2 = type1;
	ClapTrap	type5("5gou");

	type4.attack("omae");
	type1.takeDamage(5);
	type1.takeDamage(4);
	type3.beRepaired(33);
	type4.takeDamage(20);
	type4.attack("dareka");
	type4.beRepaired(1000);
	type3.takeDamage(20);
	for(int i = 0; i < 6; i ++)
	{
		type5.attack("you");
		type5.beRepaired(1000);
	}
	std::cout << "Name " << type5.getName() << " HP " << type5.getHitpoint()
				<< " Energy " << type5.getEnergy() << " Attack " << type5.getAttack() << std::endl;
}