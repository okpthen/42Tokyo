#include "file.hpp"

File::File(void){}

File::File(char **ac)
{
	_name = ac[1];
	_s1 = ac[2];
	_s2 = ac[3];
	_rename = _name + ".replace";
}

File::~File(){}

int	File::replace(void)
{
	std::ifstream	ifs(_name.c_str());
    std::string		str;
	size_t			i;

    if (ifs.fail())
	{
        std::cerr << "Failed to open file." << std::endl;
        return (-1);
    }
	std::ofstream	ofs(_rename.c_str());
    while (getline(ifs, str))
	{
		// std::cout << str.find(_s1) << " "<<std::string::npos << std::endl ;
		while ((i = str.find(_s1)) != std::string::npos)
		{
			str.erase(i, _s1.size());
			str.insert(i, _s2);
		}
		ofs << str << std::endl;
	}
	ofs.close();
	ifs.close();
	return (0);
}