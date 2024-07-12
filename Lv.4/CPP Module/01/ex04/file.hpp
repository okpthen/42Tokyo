#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <cctype>
# include <string>
# include <fstream>

class File
{
	private:
		std::string	_name;
		std::string	_s1;
		std::string	_s2;
		std::string _rename;
	public:
		File(char **ac);
		File();
		~File();
		int	replace(void);
};

#endif