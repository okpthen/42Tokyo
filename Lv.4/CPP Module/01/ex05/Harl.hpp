#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <map>

class Harl
{
	public:
		void complain( std::string level );
		Harl();
		~Harl();
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

typedef void (Harl::*t_func)(void);

#endif