#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
		// ScavTrap	type1;
		// ScavTrap	type2("oresama");
		// ScavTrap	type3(type2);
		// ScavTrap	type4("4gou");
		// type1 = type2;
		// ScavTrap	type5("5gou");

		// type1.guardGate();
		// type1.guardGate();

		// type1.takeDamage(0);
		// type2.takeDamage(0);
		// type3.takeDamage(0);
		// type4.takeDamage(0);
		// type5.takeDamage(0);

		// type4.attack("omae");
		// type1.takeDamage(5);
		// type1.takeDamage(4);
		// type3.beRepaired(33);
		// type4.takeDamage(200);
		// type4.attack("dareka");
		// type4.beRepaired(1000);
		// type3.takeDamage(20);
		// for(int i = 0; i < 26; i ++)
		// {
		// 	type5.attack("you");
		// 	type5.beRepaired(10);
		// }
	FragTrap	minion1("minion");
	FragTrap	minion2(minion1);
	FragTrap	minion3;
	std::cout << "Name " << minion1.getName() << " HP " << minion1.getHitpoint()
				<< " Energy " << minion2.getEnergy() << " Attack " << minion1.getAttack() << std::endl;

	minion3 = minion1;
	// minion2 = minion1;

	minion1.highFivesGuys();
	minion2.attack("champion");
	std::cout << "owri\n";
}