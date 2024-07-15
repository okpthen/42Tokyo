#ifndef SERVER_HPP
# define SERVER_HPP

#include "irc.hpp"
#include "SocketServer.hpp"

class	Client;
class	Channel;

class SocketServer;

class	Server
{
	protected:
		std::vector<Client*>	_Client;
		std::vector<Channel*>	_Channel;
		std::string				_PassWord;
	public:
		SocketServer *s;
		Server();
		~Server();

		void	set_pass(const std::string &pass);
		void	add_client(Client * client);
		void	add_channel(Channel * channel);
		void	remove_channel(Channel * channel);
		void	remode_client(int fd);

		std::string	get_pass();
		void		print_client();
		void		print_channel();

		Client*		get_client(const std::string nick);
		Channel*	get_channel(const std::string name);
		Client*		get_client_from_fd(int fd);
};

#endif