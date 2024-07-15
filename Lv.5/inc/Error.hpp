#ifndef ERROR_HPP
# define ERROR_HPP

#include <string>
#include <vector>

#define UNKNOWN_ERROR 999

class Client;

class	Error
{
	protected:
		Client*						_client;
		std::string					_command;
		std::vector<std::string>	_arr;
	public:
		Error();
		~Error();
		void	print_err(int num);
};

#endif