#include "Harl.hpp"

int main (int ac, char **av)
{
	Harl	harl[ac];

	if (ac == 1)
	{
		std::cout << "Usage: ./harlFilter level" << std::endl;
		return (0);
	}
	for(int  i = 1; i < ac; i ++)
		harl[i].complain(av[i]);
	return (0);
}