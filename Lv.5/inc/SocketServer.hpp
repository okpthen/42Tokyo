#ifndef SOCKETSERVER_HPP
#define SOCKETSERVER_HPP

#include  "irc.hpp"
#include "Client.hpp"
#include "Server.hpp"

class Server;

class SocketServer {
	private:
		int					_server_fd;
		int					_port;
		struct sockaddr_in	_address;
		std::vector<pollfd>	_fds;
		Server				*_serv;
		void   				checkFdStat();
		void   				addNewClient();
		void				addNewClientToServer(Server s);
		std::string			getClientCommand(size_t &i);

	public:
		SocketServer();
		SocketServer(int port, Server *serv);
		~SocketServer();
		SocketServer(const SocketServer &other);
		SocketServer	&operator=(const SocketServer &other);
		std::vector<std::pair<std::string, int> > getCommandVector();
		void	remove_fd(int fd);
};

#endif