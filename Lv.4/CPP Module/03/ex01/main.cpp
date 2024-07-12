#include "ScavTrap.hpp"

int main ()
{
	// {
	// 	ClapTrap	type2;
	// 	ClapTrap	type1("ore");
	// 	ClapTrap	type3(type1);
	// 	ClapTrap	type4("4gou");
	// 	type2 = type1;
	// 	ClapTrap	type5("5gou");

	// 	type4.attack("omae");
	// 	type1.takeDamage(5);
	// 	type1.takeDamage(4);
	// 	type3.beRepaired(33);
	// 	type4.takeDamage(20);
	// 	type4.attack("dareka");
	// 	type4.beRepaired(1000);
	// 	type3.takeDamage(20);
	// 	for(int i = 0; i < 6; i ++)
	// 	{
	// 		type5.attack("you");
	// 		type5.beRepaired(1000);
	// 	}
	// }
		ScavTrap	type1;
		ScavTrap	type2("oresama");
		ScavTrap	type3(type2);
		ScavTrap	type4("4gou");
		type1 = type2;
		ScavTrap	type5("5gou");
		std::cout << "Name " << type5.getName() << " HP " << type5.getHitpoint()
				<< " Energy " << type5.getEnergy() << " Attack " << type5.getAttack() << std::endl;

		type1.guardGate();
		type1.guardGate();

		type1.takeDamage(0);
		type2.takeDamage(0);
		type3.takeDamage(0);
		type4.takeDamage(0);
		type5.takeDamage(0);

		type4.attack("omae");
		type5.attack("omae");
		type1.attack("omae");
		type2.attack("omae");
		type3.attack("omae");
		type1.takeDamage(5);
		type1.takeDamage(4);
		type3.beRepaired(33);
		type4.takeDamage(200);
		type4.attack("dareka");
		type4.beRepaired(1000);
		type3.takeDamage(20);
		// for(int i = 0; i < 26; i ++)
		// {
		// 	type5.attack("you");
		// 	type5.beRepaired(10);
		// }

	std::cout << "owri\n";
}