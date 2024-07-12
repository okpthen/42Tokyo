#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void	Harl::debug(void)
{
	std::cout << "\033[31m[ DEBUG ]" << std::endl;
	std::cout << "\033[0mI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\033[31m[ INFO ]" << std::endl;
	std::cout << "\033[0mI cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\033[31m[ WARNING ]" << std::endl;
	std::cout << "\033[0mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "\033[31m[ ERROR ]" << std::endl;
	std::cout << "\033[0mThis is unacceptable! I want to speak to the manager now."<< std::endl;
}

void Harl::complain(std::string level)
{
	t_func		func[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4 && levels[i].compare(level))
		i ++;
	switch (i)
	{
		case 0:
			(this->*func[i])();
			i ++;
			// fall through
		case 1:
			(this->*func[i])();
			i ++;
			// fall through
		case 2:
			(this->*func[i])();
			i ++;
			// fall through
		case 3:
			(this->*func[i])();
			break ;
		default:
			std::cerr << "Invalid level: " << level << std::endl;
			break ;
	}
}
