#include "Server.hpp"

Server::Server(){}
Server::~Server()
{
	std::vector<Channel*>::iterator del;
	std::vector<Channel*>::iterator it = _Channel.begin();
	while (it != _Channel.end())
	{
		del = it;
		it ++;
		delete(*del);
	}
	std::vector<Client*>::iterator del2;
	std::vector<Client*>::iterator it2 = _Client.begin();
	while (it2 != _Client.end())
	{
		del2 = it2;
		it2 ++;
		delete(*del2);
	}
}

void	Server::set_pass(const std::string &pass){_PassWord = pass;}
void	Server::add_client(Client * client){_Client.push_back(client);}
void	Server::add_channel(Channel * channel){_Channel.push_back(channel);}

void	Server::remode_client(int fd)
{
    for (std::vector<Client*>::iterator it = _Client.begin(); it != _Client.end(); ++it)
    {
        if ((*it)->get_fd() == fd)
        {
			for (std::vector<Channel*>::iterator ic = _Channel.begin();
					ic != _Channel.end(); ic ++)
				(*ic)->is_invited(*it);
            delete *it; // 先に要素を解放する
            it = _Client.erase(it); // 要素を削除し、イテレータを更新する
            break;
        }
    }
}


void	Server::remove_channel(Channel * channel)
{
	for(std::vector<Channel*>::iterator it = _Channel.begin(); it != _Channel.end(); it++)
	{
		if (*it == channel)
		{
			_Channel.erase(it);
			delete(channel);
			break ;
		}
	}
}

std::string	Server::get_pass(){return _PassWord;}

void	Server::print_client()
{
	std::cout << "Client size\t" << _Client.size() << std::endl<< std::endl;
	for (std::vector<Client*>::iterator it = _Client.begin(); it != _Client.end(); it++)
	{
		// std::cout << (*it)->get_nick() << std::endl;
		(*it)->print_all();
		if (it+1 != _Client.end())
			std::cout << std::endl;
	}
}

void	Server::print_channel()
{
	std::cout << "Channel size\t" << _Channel.size() << std::endl<< std::endl;
	for(std::vector<Channel*>::iterator it = _Channel.begin(); it != _Channel.end(); it++)
	{
		// std::cout << (*it)->get_name() << std::endl;
		(*it)->print_all();
		if (it+1 != _Channel.end())
		std::cout << std::endl;
	}
}

Channel*	Server::get_channel(const std::string name)
{
	for(std::vector<Channel*>::iterator it = _Channel.begin(); it != _Channel.end(); it++)
	{
		if ((*it)->get_name() == name)
		{
			return (*it);
		}
	}
	return (NULL);
}

Client*		Server::get_client(const std::string nick)
{
	for(std::vector<Client*>::iterator it = _Client.begin(); it != _Client.end(); it++)
	{
		if ((*it)->get_nick() == nick)
		{
			return (*it);
		}
	}
	return (NULL);
}

Client*	Server::get_client_from_fd(int fd)
{
	for(std::vector<Client*>::iterator it = _Client.begin(); it != _Client.end(); it++)
	{
		if ((*it)->get_fd() == fd)
		{
			return (*it);
		}
	}
	return (NULL);
}